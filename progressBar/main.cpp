#include <chrono>
#include <iostream>
#include <thread>

void printProgress(float progress) {
  constexpr int barWidth =
      50; // 使用 constexpr 常量定义进度条宽度，提高性能和代码清晰度
  int pos = static_cast<int>(barWidth * progress);

  std::cout << "[";
  for (int i = 0; i < barWidth; ++i) {
    if (i < pos) {
      std::cout << "="; // 已完成部分使用 "=" 符号表示
    } else if (i == pos) {
      std::cout << ">"; // 当前进度位置使用 ">" 符号表示
    } else {
      std::cout << " "; // 未完成部分使用空格填充
    }
  }

  std::cout << "] " << static_cast<int>(progress * 100.0)
            << " %\r"; // 使用 \r 实现在同一行刷新输出
  std::cout.flush();   // 强制刷新缓冲区，立即输出到控制台
}

void progressBar() {
  constexpr int total = 100; // 使用 constexpr 常量定义总进度
  for (int i = 0; i <= total; ++i) {
    float progress = static_cast<float>(i) / total;
    printProgress(progress);
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
  }

  std::cout << std::endl;
}

int main() {
  progressBar();
  return 0;
}
