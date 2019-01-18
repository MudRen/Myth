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
        write(GRN + "\nǧ���۸����㣺����"+chinese_number(num)+
            "���ţ��뵽�ϳǿ�ջ��һ�ˣ�����\n\n" + NOR);
    }

    destruct(mbx);
}
