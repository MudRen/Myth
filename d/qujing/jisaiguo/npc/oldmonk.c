inherit NPC;

void create()
{
        set_name("�Ϻ���", ({"heshang"}));
        set("long", "һλ�Ϻ��У����������Ƶĺܣ����ﻹ��ͣ��ӽ����\n");

        set("gender", "����");
        set("attitude", "peaceful");
        set("class", "bonze");

        set("age", 60+random(20));
        set("combat_exp", 1000);
        set("shen_type", 1);
        set("per", 25);
        set("max_kee", 380);
        set("max_gin", 300);
        set_skill("force", 20+random(20));
        set_skill("unarmed", 20+random(20));
        set_skill("dodge", 20+random(20));
        set_skill("parry", 20+random(40));
set("inquiry", ([
"ԩ��": "��ʧ�ԣ��ҵ������ѵ�⣬�಻�����ǣ�\n",
"��": "��ԭ�����������ϡ�\n",
"������" : "�������������к�Ժ��\n",
]));
        setup();
        carry_object("/d/obj/cloth/sengyi")->wear();

        setup();
}


void init()
{       
        object ob=this_player();

        ::init();

                        remove_call_out("greeting");
                        call_out("greeting", 3, ob);
}
void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;

        switch( random(3) ) {
                case 0:
                command("sign");
                break;
                case 1:
                message_vision("$N̾�����ҵ�ʵ����ԩ���ģ�\n", this_object());
                break;
        }
}
