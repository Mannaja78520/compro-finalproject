#include <iostream>
#include <SFML/Graphics.hpp>

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "เกมจีบหนุ่ม");

    sf::Font font;
    if (!font.loadFromFile("src/fonts/Arial.ttf")) {
        // จัดการกับข้อผิดพลาดการโหลดฟอนต์
    }

    sf::Text startText;
    startText.setFont(font);
    startText.setString("กด Space เพื่อเริ่มเกม");
    startText.setCharacterSize(24);
    startText.setFillColor(sf::Color::White);
    startText.setPosition(250.f, 300.f);

    sf::Text affectionText;
    affectionText.setFont(font);
    affectionText.setCharacterSize(18);
    affectionText.setFillColor(sf::Color::White);
    affectionText.setPosition(10.f, 10.f);

    int affectionMeter = 0;
    bool gameStarted = false;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Space) {
                    gameStarted = true;
                }
            }
        }

        window.clear();

        if (!gameStarted) {
            window.draw(startText);
        } else {
            // ตรวจสอบภารกิจและเพิ่มความชอบ
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
                affectionMeter += 5;
            }

            // แสดงความชอบ
            affectionText.setString("ความชอบ: " + std::to_string(affectionMeter));
            window.draw(affectionText);

            // คำถามตอบ
            sf::Text questionText;
            questionText.setFont(font);

            // คำถาม 1
            questionText.setString("ถ้าคุณชอบฉัน กด A");
            questionText.setCharacterSize(20);
            questionText.setFillColor(sf::Color::White);
            questionText.setPosition(200.f, 300.f);
            window.draw(questionText);

            // คำถาม 2
            questionText.setString("ถ้าคุณต้องการเจอกันในวันหยุด กด B (ลดความชอบเพิ่มขึ้น)");
            questionText.setPosition(200.f, 350.f);
            window.draw(questionText);

            // คำถาม 3
            questionText.setString("ถ้าคุณอยากไปดูหนังด้วยกัน กด C (ลดความชอบเพิ่มขึ้น)");
            questionText.setPosition(200.f, 400.f);
            window.draw(questionText);

            // คำถาม 4
            questionText.setString("ถ้าคุณชอบทะเล กด D (ลดความชอบเพิ่มขึ้น)");
            questionText.setPosition(200.f, 450.f);
            window.draw(questionText);

            // ตรวจสอบการตอบถูกหรือผิด
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
                sf::Text correctText;
                correctText.setFont(font);
                correctText.setString("คำตอบถูก! ความชอบเพิ่มขึ้น");
                correctText.setCharacterSize(20);
                correctText.setFillColor(sf::Color::Green);
                correctText.setPosition(200.f, 500.f);
                window.draw(correctText);
            } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::B)) {
                sf::Text wrongText;
                wrongText.setFont(font);
                wrongText.setString("คำตอบผิด! ความชอบลดลง (Bad End)");
                wrongText.setCharacterSize(20);
                wrongText.setFillColor(sf::Color::Red);
                wrongText.setPosition(200.f, 500.f);
                window.draw(wrongText);
                affectionMeter -= 10; // ลดความชอบเมื่อตอบผิด
            } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::C) || sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
                sf::Text wrongText;
                wrongText.setFont(font);
                wrongText.setString("คำตอบผิด! ความชอบลดลง (Bad End)");
                wrongText.setCharacterSize(20);
                wrongText.setFillColor(sf::Color::Red);
                wrongText.setPosition(200.f, 500.f);
                window.draw(wrongText);
                affectionMeter -= 8; // ลดความชอบเมื่อตอบผิด
            }

            // ตรวจสอบเงื่อนไขการจบเกม
            if (affectionMeter <= 0) {
                sf::Text badEndText;
                badEndText.setFont(font);
                badEndText.setString("Bad End: ความชอบต่ำเกินไป จบเกม!");
                badEndText.setCharacterSize(30);
                badEndText.setFillColor(sf::Color::Red);
                badEndText.setPosition(150.f, 250.f);
                window.draw(badEndText);
                window.display();
                sf::sleep(sf::seconds(3)); // รอ 3 วินาทีก่อนจบเกม
                window.close();
            } else if (affectionMeter >= 50) {
                sf::Text goodEndText;
                goodEndText.setFont(font);
                goodEndText.setString("Good End: ความชอบสูงมาก! จบเกม");
                goodEndText.setCharacterSize(30);
                goodEndText.setFillColor(sf::Color::Green);
                goodEndText.setPosition(150.f, 250.f);
                window.draw(goodEndText);
                window.display();
                sf::sleep(sf::seconds(3)); // รอ 3 วินาทีก่อนจบเกม
                window.close();
            }

            // โค้ดส่วนอื่น ๆ ของเกมไปที่นี่
        }

        window.display();
    }

    return 0;
}