#pragma once

#include "binary_tree.h"
#include "test_framework.h"
#include "tests.h"

void interface() {
    binary_tree<int> bt({8, 3, 10, 1, 6, 14, 4, 7, 13});
    std::cout << "Binary Tree\n"
                 "Default Tree:\n"
                 "     8\n"
                 "    /  \\\n"
                 "   3    10\n"
                 "  / \\    \\\n"
                 " 1   6    14\n"
                 "    / \\   |\n"
                 "   4   7  13\n";


    while (true) {
        std::cout << "1. klp tree; 2. kpl tree; 3.lpk tree; 4.lkp tree; 5.plk tree; 6.pkl tree\n"
                     "7. Add Element\n"
                     "8. Search Element\n"
                     "9. Delete Element\n"
                     "10. Balance Tree\n"
                     "11. Map(decrement)\n"
                     "12. Where(elements more than 3)\n"
                     "13. Reduce(multiply al elements)\n"
                     "14. Run Tests\n"
                     "15. Exit\n"
                     "Enter: ";
        int answer;
        std::cin >> answer;
        switch (answer) {
            case 1:
                std::cout << bt.klp_tree() << endl;
                break;
            case 2:
                std::cout << bt.kpl_tree() << endl;
                break;
            case 3:
                std::cout << bt.lpk_tree() << endl;
                break;
            case 4:
                std::cout << bt.lkp_tree() << endl;
                break;
            case 5:
                std::cout << bt.plk_tree() << endl;
                break;
            case 6:
                std::cout << bt.pkl_tree() << endl;
                break;
            case 7:
                {
                    std::cout << "Enter number: ";
                    int item = 0;
                    std::cin >> item;
                    bt.AddElement(item);
                    std::cout << "Element added\n";
                }
                break;
            case 8:
                {
                    std::cout << "Enter number: ";
                    int item = 0;
                    std::cin >> item;
                    if (bt.SearchElement(item)) {
                        std::cout << "Element is fount";
                    }
                    else {
                        std::cout << "No element";
                    }
                }
                break;
            case 9:
                {
                    std::cout << "Enter number: ";
                    int item = 0;
                    std::cin >> item;
                    if (bt.DeleteElement(item)) {
                        std::cout << "Deleted Successfully\n";
                    }
                    else {
                        std::cout << "No element\n";
                    }
                }
                break;
            case 10:
                bt.BalanceTree();
                break;
            case 11:
                bt.Map(decrement);
                break;
            case 12:
                bt.Where(more_then_three);
                break;
            case 13:
                bt.Reduce(multiply_items, 1);
                break;
            case 14:
                TestAll();
                break;
            default:
                exit(0);
        }
    }
}

