//cigar
inherit F_VENDOR_SALE;


//inherit NPC;

#include <ansi.h>
int give_qingren();
void create()
{
         set_name(HIW"С����"NOR, ({"xiao cigar"}));
   set ("long", HIR@LONG


     ��λ�������˽ڵ������ʹ�������(ask xiao cigar)��ȡ����

     ��Ҫ��ȡ���˽��������Ҫ��ʮ�����������ϵ���ѧ���У�

     �ڴ�ףԸ����´����֣��ϼҿ��֣������³ɣ��������⣡

     ���˽������İ����˿��ֵĶȹ�����������ף������Ը��


        (����˵����wxû��12.5��ask��֮�󽫲��ٸ��������ͷ�̰�ģ�����֮�ˣ�
LONG);
           set("gender", "����");
        set("title",HIY"��"+HIB"��"+HIR"���˽�����Сʹ"+HIM"��"+HIG"��"NOR);
        set("age", 28);
        set("per", 40);
        set("attitude", "peaceful");
        set("inquiry", ([
            "����"    :(:give_qingren:),
            "Լ��"    :(:give_qingren:),
            "����"    :(:give_qingren:),
   ]));
        setup();
        carry_object("/d/obj/flower/rose999")->wear();
        carry_object("/u/cigar/obj/adier/marrys")->wear();
}
int give_qingren()
{
        object who=this_player();
        if (!userp(who)){
                  command("say ��Ҫ������");
                return 1;
        }

         if (who->query("combat_exp") < 125000 ){
                command("joke "+who->query("id") );
                command("say ץ��ʱ��ȥ�����ɣ�����ʱ�䡣");
                command("wave "+who->query("id") );
                return 1;
         }
         if (this_player()->query("lucky/qingren") > 0 ){
         message_vision("\n$N"+HIG"����"+HIY"$n"+HIG"һ���ƹ��˹���������Ҫ���Ķ������뱳�Ѱ��顱��\n",this_object(),this_player());
                command("say �Ѿ��ù����˽������ˣ����껹�У�\n");
        return 1;
        }
        who->add("potential",100000);
        who->add("kar",1);
        who->add("str",1);
        who->add("combat_exp",100000);
        who->add("daoxing",150000);
        who->add("per",1);
        who->set("lucky/qingren",1);
message_vision("\n$N"+HIR"����"+HIG"$n"+HIR"˵����"+HIY"��ףԸ��������֣�����ףԸ�����˽��������Ҹ���\n"NOR,this_object(),this_player());
        command("say  "+who->query("name")+"�õ���
               ��ѧʮ���!\n 
               ��������->����������һ��!\n 
               ��������->��Ե������һ��!\n 
               Ǳ��������ʮ���!\n 
               ����������һ����ʮ��!\n 
               ��������->��ò����һ��\n");
                  return 1;
}

