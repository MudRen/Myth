//ħ��ʥսNPC - �����ƻ���纣֮������(δ���)
//by junhyun@SK
#include <ansi.h>
inherit NPC;
int give_gift();

void create()
{
        set_name(HIW"������"NOR, ({"jalate"}));
        set("title", HIR"�����ƻ���"NOR );
        set("nickname", HIC"�纣��"NOR );
        set("gender", "����" );
        set("age", 21);
        set("per", 40);
        set("str", 30);
            set ("long", @LONG
������Ĳ���������ƻ�����걻����������������
�������������޾����ֻ��С�
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
           "name" : "�ߣ���֪���ҵ����֣���Ҫ��Ѫ�����죡\n",
     "here" : "�����Ǻڰ��ı�Ե����Ҫ��Ҫ���������ǣ�\n",
         ]) );


            setup();
}


