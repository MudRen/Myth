// NPC ����

inherit NPC;

void create()
{
       set_name("������ʿ", ({"yinshi"}));
       set("long", "��������ӵ�������ʿ.\n");
       set("title", "���ְ���");
       set("gender", "����");
        set("combat_exp", 100000);
        set("daoxing", 30000);
       set("age", 45);
       set("attitude", "friendly");
       set("shen_type", 1);
       set_skill("unarmed", 120);
        setup();
       add_money("gold", 1);
}

