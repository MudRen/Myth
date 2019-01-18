#include <ansi.h>

inherit F_VENDOR_SALE;

void create()
{
        set_name("��ũ", ({ "hua nong", "hua", "nong" }));
        set("title", HIY "��������" NOR); 
        set("gender", "����");
        set("long", "һ���������ص���ũ���������������Ի�\n"
                    "�ֲ���ʮ�꣬�����Ҳ���ڴ��ֻ�������\n"
                    "������һЩ���ӡ�\n");
        set("str", 100);
        set_skill("unarmed", 50);
        set_skill("dodge", 50);
        set_temp("apply/damage", 15);
        set("combat_exp", 800000);
        set("attitude", "friendly");

        set("vendor_goods", ([
                "seed" : "/d/luoyang/obj/seed",
        ]));

        setup();

        carry_object("/d/obj/cloth/linen")->wear();
}

void init()
{
        ::init();
        add_action("do_vendor_list", "list");
}


