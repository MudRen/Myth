//ʮ����֮ҹ٤����������
#include <ansi.h>
inherit NPC;

void create()
{
        set_name("��������", ({"xizikawa youmai","youmei"}));
        set("nickname", HIB"ҹ٤"NOR  );
        set("title", HIW"ʮ����"NOR );
        set("gender", "Ů��" );
        set("age", 21);
        set("per", 40);
        set("str", 20);
            set ("long", @LONG
����Ϊ������������Ϊ�����������ռ˵������󿴴�
��̬�ȸе������������ߵ���־־����ʵ����ߣ���
����־־�۽������ľ���ʱ����һֱŬ����ϣ��ȥ
�����Լ����������ˣ���ʹʧȥ����Ҳ������ϧ��
LONG);

        set("combat_exp", 5000000);
        set("daoxing", 900000000);
        set_skill("unarmed", 300);
        set_skill("dodge", 300);
        set_skill("force", 300);
        set_skill("spells",300);
        set("max_kee", 3000);
        set("max_sen", 3000);
        set("force", 6000);
        set("max_force", 3000);
        set("mana", 6000);
        set("max_mana", 3000);  
        set("force_factor", 10);
        set("mana_factor", 10);
        set("inquiry", ([
           "name" : "�Ҿ���ʮ����֮ҹ٤����������\n",
     "here" : "��Ҳ��֪���������\n",
     "־־��" : "�����������ˣ�������������Ӣ�ۣ�\n",
     "ʮ����" : "���ǲ�����սʤʮ�����ģ�\n", 
         ]) );


            setup();
}

