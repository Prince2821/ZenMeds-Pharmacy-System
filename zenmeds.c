#include<stdio.h>

struct Med {
    int id;
    char name[30];
    int qty;
    float price;
};

int main() {
    struct Med m[50];
    int n=0,choice,i,searchId,buyQty,found;
    char patient[30];
    float total=0,billAmt=0;

    do{
        printf("\n=== ZENMEDS PHARMACY ===\n");
        printf("1. Add Medicine\n");
        printf("2. View Stock & Update HTML Stock Page\n");
        printf("3. Search Medicine\n");
        printf("4. Make Bill & HTML Receipt\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d",&choice);

        if(choice==1){
            printf("Enter Medicine ID: ");
            scanf("%d",&m[n].id);
            printf("Enter Medicine Name (one_word): ");
            scanf("%s",m[n].name);
            printf("Enter Quantity: ");
            scanf("%d",&m[n].qty);
            printf("Enter Price: ");
            scanf("%f",&m[n].price);
            n++;
            printf("Medicine added successfully!\n");
        }else if(choice==2){
            if(n==0){
                printf("Stock is empty!\n");
            }else{
                FILE *fp=fopen("stock.html","w");
                fprintf(fp,"<html><body bgcolor='#e0f7fa'><center>");
                fprintf(fp,"<h1>ZENMEDS LIVE INVENTORY</h1>");
                fprintf(fp,"<hr width='50%%' color='#00796b'>");
                fprintf(fp,"<table border='2' cellpadding='10' bgcolor='white' width='60%%'>");
                fprintf(fp,"<tr bgcolor='#00796b'><th><font color='white'>ID</font></th><th><font color='white'>Medicine Name</font></th><th><font color='white'>Qty</font></th><th><font color='white'>Price</font></th><th><font color='white'>Status</font></th></tr>");

                printf("\nID\tName\t\tQty\tPrice\tStatus\n");
                for(i=0;i<n;i++){
                    printf("%d\t%s\t\t%d\t%.2f\t",m[i].id,m[i].name,m[i].qty,m[i].price);
                    fprintf(fp,"<tr align='center'><td>%d</td><td>%s</td><td>%d</td><td>Rs. %.2f</td>",m[i].id,m[i].name,m[i].qty,m[i].price);
                    if(m[i].qty<5){
                        printf("LOW STOCK\n");
                        fprintf(fp,"<td><font color='red'><b>LOW STOCK</b></font></td></tr>");
                    }else{
                        printf("AVAILABLE\n");
                        fprintf(fp,"<td><font color='green'><b>AVAILABLE</b></font></td></tr>");
                    }
                }
                fprintf(fp,"</table><br><a href='index.html'><b>Back to ZenMeds Home</b></a></center></body></html>");
                fclose(fp);
                printf("\n--> Webpage 'stock.html' updated! View it from index.html.\n");
            }
        }else if(choice==3){
            printf("Enter Medicine ID to search: ");
            scanf("%d",&searchId);
            found=0;
            for(i=0;i<n;i++){
                if(m[i].id==searchId){
                    printf("Medicine Found!\n");
                    printf("Name: %s | Qty: %d | Price: Rs. %.2f\n",m[i].name,m[i].qty,m[i].price);
                    found=1;
                    break;
                }
            }
            if(found==0){
                printf("Medicine not found.\n");
            }
        }else if(choice==4){
            printf("Enter Patient Name (one_word): ");
            scanf("%s",patient);
            printf("Enter Medicine ID to buy: ");
            scanf("%d",&searchId);
            found=0;
            for(i=0;i<n;i++){
                if(m[i].id==searchId){
                    found=1;
                    printf("Enter Quantity: ");
                    scanf("%d",&buyQty);
                    if(buyQty<=m[i].qty){
                        total=buyQty*m[i].price;
                        billAmt=total+(total*0.05);
                        m[i].qty=m[i].qty-buyQty;

                        printf("\n--- ZENMEDS BILL ---\n");
                        printf("Patient: %s\n",patient);
                        printf("Medicine: %s\n",m[i].name);
                        printf("Quantity: %d\n",buyQty);
                        printf("Total with 5%% GST: Rs. %.2f\n",billAmt);

                        FILE *fp=fopen("bill.html","w");
                        fprintf(fp,"<html><body bgcolor='#e0f7fa'><center>");
                        fprintf(fp,"<h1>ZENMEDS PHARMACY</h1>");
                        fprintf(fp,"<h3>Official Patient Receipt</h3><hr width='40%%' color='#00796b'>");
                        fprintf(fp,"<table border='2' cellpadding='12' bgcolor='white' width='40%%'>");
                        fprintf(fp,"<tr bgcolor='#00796b'><th colspan='2'><font color='white'>BILL DETAILS</font></th></tr>");
                        fprintf(fp,"<tr><td><b>Patient Name</b></td><td>%s</td></tr>",patient);
                        fprintf(fp,"<tr><td><b>Medicine</b></td><td>%s</td></tr>",m[i].name);
                        fprintf(fp,"<tr><td><b>Quantity</b></td><td>%d</td></tr>",buyQty);
                        fprintf(fp,"<tr><td><b>Price per Unit</b></td><td>Rs. %.2f</td></tr>",m[i].price);
                        fprintf(fp,"<tr bgcolor='#fff9c4'><td><b>Grand Total (5%% GST)</b></td><td><b>Rs. %.2f</b></td></tr>",billAmt);
                        fprintf(fp,"</table><p><i>Thank you! Get well soon!</i></p>");
                        fprintf(fp,"<a href='index.html'><b>Back to ZenMeds Home</b></a></center></body></html>");
                        fclose(fp);

                        printf("--> Webpage 'bill.html' updated! View it from index.html.\n");
                    }else{
                        printf("Out of stock! Only %d left.\n",m[i].qty);
                    }
                    break;
                }
            }
            if(found==0){
                printf("Medicine ID not found.\n");
            }
        }else if(choice==5){
            printf("Thank you for using ZenMeds!\n");
        }else{
            printf("Invalid choice!\n");
        }
    }while(choice!=5);

    return 0;
}