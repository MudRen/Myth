//ħ��ʥսNPC - ������֮�ǻ۰�����(δ���)
//by junhyun@SK
#include <ansi.h>
inherit NPC;
int give_gift();

void create()
{
        set_name(HIW"������"NOR, ({"annieya"}));
        set("title", HIC"��������"NOR );
        set("nickname", HIW"�ǻ�Ů��"NOR );
        set("gender", "Ů��" );
        set("age", 21);
        set("per", 40);
        set("str", 30);
            set ("long", @LONG
��������֮һ��ӵ�й�����������
LONG);

        set("combat_exp", 290000);
        set("daoxing", 40000000000);
        set_skill("unarmed", 370);
        set_skill("dodge", 340);
        set("max_kee", 10000);
        set("max_sen", 10000);
        set("force", 6000);
        set("max_force", 3000);
        set("mana", 6000);
        set("max_mana", 3000);  
        set("force_factor", 1000);
        set("mana_factor", 1000);
        set("inquiry", ([
           "name" : "�Ҿ�������Ů�����š�\n",
     "here" : "�����ǹ���ʥ�������ʿ������֮�ء�\n",
         ]) );


            setup();
}


