#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QSlider>
#include <QProgressBar>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QListWidget>
#include <QPixmap>
#include <QPalette>
#include <QBrush>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    // -----------------------------
    // WINDOW
    // -----------------------------
    QWidget window;
    window.setWindowTitle("STM32MP1 Qt UI");
    window.showFullScreen();   // <-- pełny ekran

    // -----------------------------
    // BACKGROUND IMAGE (FULL SCREEN)
    // -----------------------------
    QPixmap bg("/usr/share/first-qt/logo.png");

    QPalette palette;
    palette.setBrush(QPalette::Window, bg.scaled(
        window.size(),
        Qt::IgnoreAspectRatio,
        Qt::SmoothTransformation
    ));

    window.setAutoFillBackground(true);
    window.setPalette(palette);

    // -----------------------------
    // UI ELEMENTS
    // -----------------------------
    QLabel *label = new QLabel("Witaj na STM32MP1!");
    label->setStyleSheet("font-size: 28px; font-weight: bold; color: white;");

    QLineEdit *edit = new QLineEdit();
    edit->setPlaceholderText("Wpisz coś...");

    QPushButton *button = new QPushButton("Kliknij");

    QListWidget *list = new QListWidget();
    list->addItem("Element 1");
    list->addItem("Element 2");
    list->addItem("Element 3");

    QSlider *slider = new QSlider(Qt::Horizontal);
    slider->setRange(0, 100);

    QProgressBar *progress = new QProgressBar();
    progress->setRange(0, 100);

    // -----------------------------
    // LOGIC
    // -----------------------------
    QObject::connect(button, &QPushButton::clicked, [&]() {
        list->addItem("Klik!");
    });

    QObject::connect(slider, &QSlider::valueChanged,
                     progress, &QProgressBar::setValue);

    // -----------------------------
    // LAYOUT
    // -----------------------------
    QVBoxLayout *layout = new QVBoxLayout();

    layout->addWidget(label);
    layout->addWidget(edit);
    layout->addWidget(button);
    layout->addWidget(list);
    layout->addWidget(slider);
    layout->addWidget(progress);

    window.setLayout(layout);

    window.show();

    return app.exec();
}
