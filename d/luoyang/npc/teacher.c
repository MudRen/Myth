#include <ansi.h> 
inherit NPC;

void create()
{
        set_name("��������", ({ "xian sheng","xian" }) );
        set("gender", "����" );
        set("age", 40);
        set("per", 30);
        set("long", "һλ���������������ʿ����ҡͷ���Ե��ڽ�ѧ�����顣\n");
        set("combat_exp", 1000);
        set("attitude", "friendly");
        set_skill("dodge", 15);
        set_skill("unarmed", 10);
        set_skill("parry", 15);
        set("max_kee", 400);

        set("chat_chance", 10);
        set("chat_msg", ({
                CYN "���������������֮�����Ա��ơ�\n" NOR,
                CYN "��������ҡͷ���Ե��������ع���𣚣�ں�֮�ޣ�����Ů�����Ӻ��ϡ�\n" NOR,
                CYN "������������������������������������ӣ����Ӳ������������ӡ�\n" NOR,
                CYN "��������������������߲�����������������\n" NOR,
        }));

        setup();
        add_money("silver", 5);

        carry_object("/d/gao/obj/ruler")->wield();
        carry_object("/d/gao/obj/changpao")->wear();
}

