#include <stdio.h>

void saveOrderToFile(int user, int userBill);
void saveFeedbackToFile(int user, int rating, char feedback[]);

int main() {
    int userCount;        // Number of users placing orders
    int totalBill = 0;    // Total bill for all users

    // Item prices
    int biryaniPrices[3] = {250, 400, 600};  // Small, Medium, Large
    int karahiPrices[3] = {600, 1200, 1600}; // Small, Medium, Large
    int tikkaPrices[3] = {300, 450, 600};    // Small, Medium, Large
    int drinkPrices[4] = {50, 100, 180, 250}; // 250ml, 500ml, 1L, 1.5L
    int dessertPrices[3] = {100, 150, 200};  // Ice Cream, Gulab Jamun, Cake

    printf("Welcome to Birbal's Kitchen!\n");
    printf("Enter the number of users placing orders: ");
    scanf("%d", &userCount);

    for (int user = 1; user <= userCount; user++) {
        int userBill = 0; // Total bill for the current user

        printf("\nUser %d, place your order:\n", user);

        // Ordering main dishes and drinks
        while (1) {
            printf("\n===== MENU =====\n");
            printf("1. Biryani (Small: Rs 250, Medium: Rs 400, Large: Rs 600)\n");
            printf("2. Karahi (Small: Rs 600, Medium: Rs 1200, Large: Rs 1600)\n");
            printf("3. Chicken Tikka (Small: Rs 300, Medium: Rs 450, Large: Rs 600)\n");
            printf("4. Drinks (250ml: Rs 50, 500ml: Rs 100, 1L: Rs 180, 1.5L: Rs 250)\n");
            printf("0. Proceed to Desserts\n");
            printf("=================\n");

            printf("Enter your choice (or 0 to proceed to desserts): ");
            int choice;
            scanf("%d", &choice);

            if (choice == 0) {
                break;
            }

            int size, quantity, maxQuantity = 10;
            switch (choice) {
                case 1: // Biryani
                    printf("\nYou chose Biryani.\n");
                    printf("Select size:\n1. Small (Rs 250)\n2. Medium (Rs 400)\n3. Large (Rs 600)\n");
                    printf("Enter your choice: ");
                    scanf("%d", &size);
                    if (size >= 1 && size <= 3) {
                        printf("Enter quantity (1 to %d plates): ", maxQuantity);
                        scanf("%d", &quantity);
                        if (quantity >= 1 && quantity <= maxQuantity) {
                            userBill += biryaniPrices[size - 1] * quantity;
                            printf("%d Biryani(s) (Size: %s) added to your order.\n",
                                   quantity,
                                   (size == 1) ? "Small" : (size == 2) ? "Medium" : "Large");
                        } else {
                            printf("Invalid quantity! Please enter a number between 1 and %d.\n", maxQuantity);
                        }
                    } else {
                        printf("Invalid size. Try again.\n");
                    }
                    break;

                case 2: // Karahi
                    printf("\nYou chose Karahi.\n");
                    printf("Select size:\n1. Small (Rs 600)\n2. Medium (Rs 1200)\n3. Large (Rs 1600)\n");
                    printf("Enter your choice: ");
                    scanf("%d", &size);
                    if (size >= 1 && size <= 3) {
                        printf("Enter quantity (1 to %d plates): ", maxQuantity);
                        scanf("%d", &quantity);
                        if (quantity >= 1 && quantity <= maxQuantity) {
                            userBill += karahiPrices[size - 1] * quantity;
                            printf("%d Karahi(s) (Size: %s) added to your order.\n",
                                   quantity,
                                   (size == 1) ? "Small" : (size == 2) ? "Medium" : "Large");
                        } else {
                            printf("Invalid quantity! Please enter a number between 1 and %d.\n", maxQuantity);
                        }
                    } else {
                        printf("Invalid size. Try again.\n");
                    }
                    break;

                case 3: // Chicken Tikka
                    printf("\nYou chose Chicken Tikka.\n");
                    printf("Select size:\n1. Small (Rs 300)\n2. Medium (Rs 450)\n3. Large (Rs 600)\n");
                    printf("Enter your choice: ");
                    scanf("%d", &size);
                    if (size >= 1 && size <= 3) {
                        printf("Enter quantity (1 to %d pieces): ", maxQuantity);
                        scanf("%d", &quantity);
                        if (quantity >= 1 && quantity <= maxQuantity) {
                            userBill += tikkaPrices[size - 1] * quantity;
                            printf("%d Chicken Tikka(s) (Size: %s) added to your order.\n",
                                   quantity,
                                   (size == 1) ? "Small" : (size == 2) ? "Medium" : "Large");
                        } else {
                            printf("Invalid quantity! Please enter a number between 1 and %d.\n", maxQuantity);
                        }
                    } else {
                        printf("Invalid size. Try again.\n");
                    }
                    break;

                case 4: // Drinks
                    printf("\nYou chose Drinks.\n");
                    printf("Select size:\n1. 250ml (Rs 50)\n2. 500ml (Rs 100)\n3. 1L (Rs 180)\n4. 1.5L (Rs 250)\n");
                    printf("Enter your choice: ");
                    scanf("%d", &size);
                    if (size >= 1 && size <= 4) {
                        printf("Enter quantity (1 to %d bottles): ", maxQuantity);
                        scanf("%d", &quantity);
                        if (quantity >= 1 && quantity <= maxQuantity) {
                            userBill += drinkPrices[size - 1] * quantity;
                            printf("%d Drink(s) (Size: %s) added to your order.\n",
                                   quantity,
                                   (size == 1) ? "250ml" : (size == 2) ? "500ml" : (size == 3) ? "1L" : "1.5L");
                        } else {
                            printf("Invalid quantity! Please enter a number between 1 and %d.\n", maxQuantity);
                        }
                    } else {
                        printf("Invalid size. Try again.\n");
                    }
                    break;

                default:
                    printf("Invalid choice. Try again.\n");
            }
        }

        // Ordering desserts
        while (1) {
            printf("\n===== DESSERT MENU =====\n");
            printf("1. Ice Cream (Rs 100)\n");
            printf("2. Gulab Jamun (Rs 150)\n");
            printf("3. Cake (Rs 200)\n");
            printf("0. Finish Desserts\n");
            printf("========================\n");

            printf("Enter your choice (or 0 to finish desserts): ");
            int dessertChoice;
            scanf("%d", &dessertChoice);

            if (dessertChoice == 0) {
                break;
            }

            int quantity, maxQuantity = 10;
            if (dessertChoice >= 1 && dessertChoice <= 3) {
                printf("Enter quantity (1 to %d servings): ", maxQuantity);
                scanf("%d", &quantity);
                if (quantity >= 1 && quantity <= maxQuantity) {
                    userBill += dessertPrices[dessertChoice - 1] * quantity;
                    printf("%d %s(s) added to your order.\n",
                           quantity,
                           (dessertChoice == 1) ? "Ice Cream" : (dessertChoice == 2) ? "Gulab Jamun" : "Cake");
                } else {
                    printf("Invalid quantity! Please enter a number between 1 and %d.\n", maxQuantity);
                }
            } else {
                printf("Invalid choice. Try again.\n");
            }
        }

        printf("\nUser %d, your total bill is Rs %d.\n", user, userBill);
        saveOrderToFile(user, userBill);

        printf("Please pay your bill. Enter payment amount: ");
        int payment;
        scanf("%d", &payment);

        if (payment >= userBill) {
            printf("Payment successful! Change: Rs %d\n", payment - userBill);
            totalBill += userBill;

            // Feedback
            printf("\n===== Feedback Section =====\n");
            printf("Rate our service (1-5): ");
            int rating;
            scanf("%d", &rating);
            printf("Leave a comment: ");
            char feedback[100];
            getchar(); // Consume newline
            fgets(feedback, 100, stdin);
            saveFeedbackToFile(user, rating, feedback);
            printf("\nThank you for your feedback!\n");
        } else {
            printf("Payment failed. Please try again.\n");
        }
    }

    printf("\nAll orders completed. Total bill for all users: Rs %d\n", totalBill);
    printf("\nThank you for dining with Birbal's Kitchen!\n");

    return 0;
}

// Function to save orders to a file
void saveOrderToFile(int user, int userBill) {
    FILE *orderFile = fopen("orders.txt", "a");
    if (orderFile == NULL) {
        printf("Error: Could not save order details to file.\n");
    } else {
        fprintf(orderFile, "User %d Total Bill: Rs %d\n", user, userBill);
        fclose(orderFile);
    }
}

// Function to save feedback to a file
void saveFeedbackToFile(int user, int rating, char feedback[]) {
    FILE *feedbackFile = fopen("feedback.txt", "a");
    if (feedbackFile == NULL) {
        printf("Error: Could not save feedback to file.\n");
    } else {
        fprintf(feedbackFile, "User %d Feedback:\n", user);
        fprintf(feedbackFile, "Rating: %d\nComment: %s\n", rating, feedback);
        fclose(feedbackFile);
    }
}



