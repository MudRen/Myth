// washer.c

inherit NPC;
void create()
{
       set_name("������", ({"laomaz"}));
       set("long","һ����̫�ţ���������ϴ��һ���·���\n");
       set("gender", "Ů��");
       set("age",68);
       set("attitude", "friendly");
	set("per", 15);
        set("shen_type", 1);
	set("combat_exp", 500);
        set("chat_chance",4);
        set("chat_msg", ({
                "����������ţ���ɱ�����ˣ������Ҽ�С�㣡\n",
		"�����ӵ������������������������˾����Ƕ������ģ�\n",
}) );

	setup();
}
