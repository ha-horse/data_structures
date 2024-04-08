#include "linear.cpp"
#include "nonlinear.cpp"

int main(){
    std::cout << "start test linear." << std::endl;
    std::cout << "test 1 (SeqList):" << std::endl;
    testSeqList();
    std::cout << "test 2 (LinkList):" << std::endl;
    testLinkList();
    std::cout << "test 3 (Stack):" << std::endl;
    testStack();
    std::cout << "test 4 (Queue):" << std::endl;
    testQueue();
    std::cout << "linear test end." << std::endl;
    std::cout << "start test linear." << std::endl;
    std::cout << "====================================" << std::endl;
    std::cout << "test 5 (binaryTree):" << std::endl;
    test_binaryTree();
    return 0;
}