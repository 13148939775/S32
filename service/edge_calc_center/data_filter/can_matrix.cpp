// #include <iostream>
// #include <xlslib/xlslib.h>

#include <iostream>
#include "canmatrix/canmatrix.h"
#include "canmatrix/importers/dbcimport.h"

void Can2() 
{
    canmatrix::Matrix canMatrix;

    // 从DBC文件中读取CAN通信描述信息
    canmatrix::DBCimport canImport("example.dbc");
    if (canImport.load(canMatrix) != canmatrix::DBCimport::Status::OK) {
        std::cerr << "Failed to import DBC file." << std::endl;
        return -1;
    }

    // 打印CAN通信描述信息
    for (const auto& frame : canMatrix.frames) {
        std::cout << "Frame Name: " << frame->name << std::endl;
        std::cout << "Frame ID: " << frame->id << std::endl;

        for (const auto& signal : frame->signals) {
            std::cout << "  Signal Name: " << signal->name << std::endl;
            std::cout << "  Signal Start Bit: " << signal->startBit << std::endl;
            std::cout << "  Signal Length: " << signal->signalSize << std::endl;
        }
    }

    return 0;
}

int CanMatrix::ConvertXLS2Def(std::string& file) 
{
    // 打开XLS文件
    xlslib_core::WorkBook xlsFile;
    xlslib_core::Sheet* sheet;
    xlslib_core::Row* row;
    xlslib_core::Cell* cell;
    
    if (xlsFile.load(file)) {
        // 获取第一个工作表
        sheet = xlsFile.getSheet(0);
        if (sheet) {
            // 获取行数和列数
            int rowCount = sheet->lastrow();
            int colCount = sheet->lastcol();

            // 遍历每一行和每一列
            for (int row = 0; row <= rowCount; ++row) {
                for (int col = 0; col <= colCount; ++col) {
                    // 读取单元格的值
                    cell = sheet->cell(row, col);
                    
                    if (cell) {
                        int type = cell->isType();
                        if (type == 3) {
                            std::cout << cell->getString() << " ";
                        } else if (type == 1) {
                            std::cout << cell->getDouble() << " ";
                        }
                    } else {
                        std::cout << " ";
                    }
                }
                std::cout << std::endl;
            }
        }
        
        // 关闭XLS文件
        xlsFile.close();
    }

    return 0;
}