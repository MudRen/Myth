//ʮ����֮�콣�������ڴ���
#include <ansi.h>
inherit NPC;

void create()
{
        set_name("�����ڴ���", ({"kasuki zinomiya","zongcilang"}));
        set("nickname", HIB"�콣"NOR  );
        set("title", HIW"ʮ����"NOR );
        set("gender", "�� ��" );
        set("age", 21);
        set("per", 40);
        set("str", 20);
            set ("long", @LONG
־־�۵�����ұۣ�Ҳ����ʮ�����������ɳ�Ϊ��ǿ
����Ž�ʿ�������������ֽ��Լ��ļ���ȫ��ɱ¾��
���ľ�����������������κ����֮�¶�ֻ��Ц����
�����ϰ�ԣ���ͬ���ĵ�ս���У�ɥʧ�Ѿõĸ����
�������������ʹ�����ձ�����־־�ۡ�
LONG);

        set("combat_exp", 150000000);
        set("daoxing", 150000000);
        set_skill("unarmed", 600);
        set_skill("dodge", 600);
        set_skill("force", 600);
        set_skill("spells",600);
        set_skill("sword",600);
        set_skill("feitian-jian",600);
        map_skill("sword", "feitian-jian");
        set("max_kee", 6000);
        set("max_sen", 6000);
        set("force", 12000);
        set("max_force", 6000);
        set("mana", 12000);
        set("max_mana", 6000);  
        set("force_factor", 100);
        set("mana_factor", 100);


        set("inquiry", ([
           "name" : "�Ҿ���ʮ����֮ҹ٤����������\n",
     "here" : "��Ҳ��֪���������\n",
     "־־��" : "�����������ˣ�������������Ӣ�ۣ�\n",
     "ʮ����" : "���ǲ�����սʤʮ�����ģ�\n", 
         ]) );


            setup();

        carry_object("d/wizz/junhyun/japan-sword1")->wield();

}

