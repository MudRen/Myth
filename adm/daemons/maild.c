#include <ansi.h>

void check_mail(object ob)
{
    int num;
    object mbx;

    mbx=ob->query_temp("mbox_ob");
    if (!mbx)
    {
        mbx=new(MAILBOX_OB);
        mbx->set_owner(ob->query("id"));
    }

    num = mbx->query_new_mail();
    if (num > 0)
    {
        write(GRN + "\n千里眼告诉你：有您"+chinese_number(num)+
            "封信！请到南城客栈来一趟．．．\n\n" + NOR);
    }

    destruct(mbx);
}
