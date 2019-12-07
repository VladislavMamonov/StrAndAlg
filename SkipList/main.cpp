#include "SkipList.hpp"


int main()
{
  skiplist ss;
  int choice, n;

  while (1)
  {
    cout << "-----------------------" << endl;
    cout << "Operations on Skip list" << endl;

    cout << "-----------------------" << endl;
    cout << "1.Insert Element" << endl;
    cout << "2.Delete Element" << endl;
    cout << "3.Search Element" << endl;
    cout << "4.Display List " << endl;
    cout << "5.Exit " << endl << endl;

    cout << "Enter your choice : ";
    cin >> choice;

    system("clear");

    switch(choice)
    {
      case 1:
        cout << "Enter the element to be inserted: ";
        cin >> n;
        ss.insert_element(n);

        if (ss.contains(n))
          cout << "Element Inserted" << endl;
        break;

      case 2:
        cout << "Enter the element to be deleted: ";
        cin >> n;
        if (!ss.contains(n)) {
          cout << "Element not found" << endl;
          break;
        }

        ss.delete_element(n);
        if (!ss.contains(n))
          cout<<"Element Deleted"<<endl;
        break;

      case 3:
        cout << "Enter the element to be searched: ";
        cin >> n;
        if (ss.contains(n))
          cout << "Element " << n << " is in the list" << endl;
        else
          cout << "Element not found" << endl;

      case 4:
        ss.display();
        break;

      case 5:
        exit(1);
        break;

        default:
          cout<<"Wrong Choice"<<endl;
    }
  }
  return 0;
}
