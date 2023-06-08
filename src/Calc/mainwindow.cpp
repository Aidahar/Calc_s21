#include "mainwindow.h"

#include "./ui_mainwindow.h"
#include "parse_string.h"
#include "calculate.h"


MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  setWindowTitle("Calculator");
  ui->parsed_x->setValidator(new QRegularExpressionValidator(
      QRegularExpression("^[0-9]{1,10}.[0-9]{1,7}"), this));
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::on_Del_clicked() {
  QPushButton* button = qobject_cast<QPushButton*>(sender());
  if (button) {
    if (ui->parsed_string->text().contains("ERROR!")) {
      ui->parsed_string->clear();
      ui->parsed_string->insert(button->text());
    } else {
      ui->parsed_string->insert(button->text());
    }
  }
}

void MainWindow::on_Mul_clicked() {
  QPushButton* button = qobject_cast<QPushButton*>(sender());
  if (button) {
    if (ui->parsed_string->text().contains("ERROR!")) {
      ui->parsed_string->clear();
      ui->parsed_string->insert(button->text());
    } else {
      ui->parsed_string->insert(button->text());
    }
  }
}

void MainWindow::on_button_tchk_clicked() {
  QPushButton* button = qobject_cast<QPushButton*>(sender());
  if (button) {
    ui->parsed_string->insert(button->text());
  }
}

void MainWindow::on_Minus_clicked() {
  QPushButton* button = qobject_cast<QPushButton*>(sender());
  if (button) {
    if (ui->parsed_string->text().contains("ERROR!")) {
      ui->parsed_string->clear();
      ui->parsed_string->insert(button->text());
    } else {
      ui->parsed_string->insert(button->text());
    }
  }
}

void MainWindow::on_plus_clicked() {
  QPushButton* button = qobject_cast<QPushButton*>(sender());
  if (button) {
    if (ui->parsed_string->text().contains("ERROR!")) {
      ui->parsed_string->clear();
      ui->parsed_string->insert(button->text());
    } else {
      ui->parsed_string->insert(button->text());
    }
  }
}

void MainWindow::on_C_clicked() {
  if (ui->parsed_string->text().contains("ERROR!")) {
    ui->parsed_string->clear();
  } else {
    ui->parsed_string->backspace();
  }
}

void MainWindow::on_percent_clicked() {
  QPushButton* button = qobject_cast<QPushButton*>(sender());
  if (button) {
    ui->parsed_string->insert(button->text());
  }
}

void MainWindow::on_AC_clicked() {
  QPushButton* button = qobject_cast<QPushButton*>(sender());
  if (button) {
    ui->parsed_string->clear();
  }
}

void MainWindow::on_button_0_clicked() {
  QPushButton* button = qobject_cast<QPushButton*>(sender());
  if (button) {
    if (ui->parsed_string->text().contains("ERROR!")) {
      ui->parsed_string->clear();
      ui->parsed_string->insert(button->text());
    } else {
      ui->parsed_string->insert(button->text());
    }
  }
}

void MainWindow::on_button_00_clicked() {
  QPushButton* button = qobject_cast<QPushButton*>(sender());
  if (button) {
    if (ui->parsed_string->text().contains("ERROR!")) {
      ui->parsed_string->clear();
      ui->parsed_string->insert(button->text());
    } else {
      ui->parsed_string->insert(button->text());
    }
  }
}

void MainWindow::on_button_1_clicked() {
  QPushButton* button = qobject_cast<QPushButton*>(sender());
  if (button) {
    if (ui->parsed_string->text().contains("ERROR!")) {
      ui->parsed_string->clear();
      ui->parsed_string->insert(button->text());
    } else {
      ui->parsed_string->insert(button->text());
    }
  }
}

void MainWindow::on_button_2_clicked() {
  QPushButton* button = qobject_cast<QPushButton*>(sender());
  if (button) {
    if (ui->parsed_string->text().contains("ERROR!")) {
      ui->parsed_string->clear();
      ui->parsed_string->insert(button->text());
    } else {
      ui->parsed_string->insert(button->text());
    }
  }
}

void MainWindow::on_button_3_clicked() {
  QPushButton* button = qobject_cast<QPushButton*>(sender());
  if (button) {
    if (ui->parsed_string->text().contains("ERROR!")) {
      ui->parsed_string->clear();
      ui->parsed_string->insert(button->text());
    } else {
      ui->parsed_string->insert(button->text());
    }
  }
}

void MainWindow::on_button_4_clicked() {
  QPushButton* button = qobject_cast<QPushButton*>(sender());
  if (button) {
    if (ui->parsed_string->text().contains("ERROR!")) {
      ui->parsed_string->clear();
      ui->parsed_string->insert(button->text());
    } else {
      ui->parsed_string->insert(button->text());
    }
  }
}

void MainWindow::on_button_5_clicked() {
  QPushButton* button = qobject_cast<QPushButton*>(sender());
  if (button) {
    if (ui->parsed_string->text().contains("ERROR!")) {
      ui->parsed_string->clear();
      ui->parsed_string->insert(button->text());
    } else {
      ui->parsed_string->insert(button->text());
    }
  }
}

void MainWindow::on_button_6_clicked() {
  QPushButton* button = qobject_cast<QPushButton*>(sender());
  if (button) {
    if (ui->parsed_string->text().contains("ERROR!")) {
      ui->parsed_string->clear();
      ui->parsed_string->insert(button->text());
    } else {
      ui->parsed_string->insert(button->text());
    }
  }
}

void MainWindow::on_button_7_clicked() {
  QPushButton* button = qobject_cast<QPushButton*>(sender());
  if (button) {
    if (ui->parsed_string->text().contains("ERROR!")) {
      ui->parsed_string->clear();
      ui->parsed_string->insert(button->text());
    } else {
      ui->parsed_string->insert(button->text());
    }
  }
}

void MainWindow::on_button_8_clicked() {
  QPushButton* button = qobject_cast<QPushButton*>(sender());
  if (button) {
    if (ui->parsed_string->text().contains("ERROR!")) {
      ui->parsed_string->clear();
      ui->parsed_string->insert(button->text());
    } else {
      ui->parsed_string->insert(button->text());
    }
  }
}

void MainWindow::on_buton_9_clicked() {
  QPushButton* button = qobject_cast<QPushButton*>(sender());
  if (button) {
    if (ui->parsed_string->text().contains("ERROR!")) {
      ui->parsed_string->clear();
      ui->parsed_string->insert(button->text());
    } else {
      ui->parsed_string->insert(button->text());
    }
  }
}

void MainWindow::on_Sqrt_clicked() {
  QPushButton* button = qobject_cast<QPushButton*>(sender());
  if (button) {
    if (ui->parsed_string->text().contains("ERROR!")) {
      ui->parsed_string->clear();
      ui->parsed_string->insert("sqrt(");
    } else {
      ui->parsed_string->insert("sqrt(");
    }
  }
}

void MainWindow::on_UnarPL_clicked() {
  QPushButton* button = qobject_cast<QPushButton*>(sender());
  if (button) {
    if (ui->parsed_string->text().contains("ERROR!")) {
      ui->parsed_string->clear();
      if (ui->parsed_string->text().endsWith("+")) {
        ui->parsed_string->backspace();
        ui->parsed_string->insert("-");
      } else if (ui->parsed_string->text().endsWith("-")) {
        ui->parsed_string->backspace();
        ui->parsed_string->insert(button->text());
      } else {
        ui->parsed_string->insert("+");
      }
    } else {
      if (ui->parsed_string->text().endsWith("+")) {
        ui->parsed_string->backspace();
        ui->parsed_string->insert("-");
      } else if (ui->parsed_string->text().endsWith("-")) {
        ui->parsed_string->backspace();
        ui->parsed_string->insert(button->text());
      } else {
        ui->parsed_string->insert("+");
      }
    }
  }
}

void MainWindow::on_L_BR_clicked() {
  QPushButton* button = qobject_cast<QPushButton*>(sender());
  if (button) {
    if (ui->parsed_string->text().contains("ERROR!")) {
      ui->parsed_string->clear();
      ui->parsed_string->insert(button->text());
    } else {
      ui->parsed_string->insert(button->text());
    }
  }
}

void MainWindow::on_R_BR_clicked() {
  QPushButton* button = qobject_cast<QPushButton*>(sender());
  if (button) {
    if (ui->parsed_string->text().contains("ERROR!")) {
      ui->parsed_string->clear();
      ui->parsed_string->insert(button->text());
    } else {
      ui->parsed_string->insert(button->text());
    }
  }
}

void MainWindow::on_sin_clicked() {
  QPushButton* button = qobject_cast<QPushButton*>(sender());
  if (button) {
    if (ui->parsed_string->text().contains("ERROR!")) {
      ui->parsed_string->clear();
      ui->parsed_string->insert("sin(");
    } else {
      ui->parsed_string->insert("sin(");
    }
  }
}

void MainWindow::on_cos_clicked() {
  QPushButton* button = qobject_cast<QPushButton*>(sender());
  if (button) {
    if (ui->parsed_string->text().contains("ERROR!")) {
      ui->parsed_string->clear();
      ui->parsed_string->insert("cos(");
    } else {
      ui->parsed_string->insert("cos(");
    }
  }
}

void MainWindow::on_tan_clicked() {
  QPushButton* button = qobject_cast<QPushButton*>(sender());
  if (button) {
    if (ui->parsed_string->text().contains("ERROR!")) {
      ui->parsed_string->clear();
      ui->parsed_string->insert("tan(");
    } else {
      ui->parsed_string->insert("tan(");
    }
  }
}

void MainWindow::on_ln_clicked() {
  QPushButton* button = qobject_cast<QPushButton*>(sender());
  if (button) {
    if (ui->parsed_string->text().contains("ERROR!")) {
      ui->parsed_string->clear();
      ui->parsed_string->insert("ln(");
    } else {
      ui->parsed_string->insert("ln(");
    }
  }
}

void MainWindow::on_log_clicked() {
  QPushButton* button = qobject_cast<QPushButton*>(sender());
  if (button) {
    if (ui->parsed_string->text().contains("ERROR!")) {
      ui->parsed_string->clear();
      ui->parsed_string->insert("log(");
    } else {
      ui->parsed_string->insert("log(");
    }
  }
}

void MainWindow::on_atan_clicked() {
  QPushButton* button = qobject_cast<QPushButton*>(sender());
  if (button) {
    if (ui->parsed_string->text().contains("ERROR!")) {
      ui->parsed_string->clear();
      ui->parsed_string->insert("atan(");
    } else {
      ui->parsed_string->insert("atan(");
    }
  }
}

void MainWindow::on_acos_clicked() {
  QPushButton* button = qobject_cast<QPushButton*>(sender());
  if (button) {
    if (ui->parsed_string->text().contains("ERROR!")) {
      ui->parsed_string->clear();
      ui->parsed_string->insert("acos(");
    } else {
      ui->parsed_string->insert("acos(");
    }
  }
}

void MainWindow::on_asin_clicked() {
  QPushButton* button = qobject_cast<QPushButton*>(sender());
  if (button) {
    if (ui->parsed_string->text().contains("ERROR!")) {
      ui->parsed_string->clear();
      ui->parsed_string->insert("asin(");
    } else {
      ui->parsed_string->insert("asin(");
    }
  }
}

void MainWindow::on_Mod_clicked() {
  QPushButton* button = qobject_cast<QPushButton*>(sender());
  if (button) {
    if (ui->parsed_string->text().contains("ERROR!")) {
      ui->parsed_string->clear();
      ui->parsed_string->insert(button->text());
    } else {
      ui->parsed_string->insert(button->text());
    }
  }
}

void MainWindow::on_X_clicked() {
  QPushButton* button = qobject_cast<QPushButton*>(sender());
  if (button) {
    if (ui->parsed_string->text().contains("ERROR!")) {
      ui->parsed_string->clear();
      ui->parsed_string->insert(button->text());
    } else {
      ui->parsed_string->insert(button->text());
    }
  }
}

void MainWindow::on_equal_clicked() {
  int X = 1;
  QString parsed = ui->parsed_string->text();
  std::string str = parsed.toStdString();
  char* data = (char*)calloc(sizeof(char), 255);
  char* polish = (char*)calloc(sizeof(char), 255);
  if (data) {
    strcpy(data, str.c_str());
  }
  int status = parse_string(data, polish);
  if (status) {
    ui->parsed_string->clear();
    double res = calculate(polish);
    std::string str_res = std::to_string(res);
    QString ans = QString::fromStdString(str_res);
    ui->parsed_string->insert(ans);
  } else {
    ui->parsed_string->clear();
    ui->parsed_string->insert("ERROR!");
  }
}

void MainWindow::on_parsed_x_returnPressed() {
    QString x = "", input = ui->parsed_string->text();
    if (input.contains('x')) {
        x = ui->parsed_x->text();
        input.replace(QRegularExpression("[x]"), x);
    } else {
        x = "1";
    }
    ui->parsed_string->setText(input);
    ui->parsed_x->releaseKeyboard();
}


