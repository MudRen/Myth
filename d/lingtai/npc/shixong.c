// worker.c

inherit NPC;
string try_me(object me);

void create()
{
        set_name("𫲻��", ({"bo bufen", "bo"}));
        set("gender", "����" );
        set("age", 33);
        set("long", "һ���ֺ����ĵ�ʿ����ɵ�ǺǵĲ�֪Цʲô��\n");
	set("class", "taoist");
        set("combat_exp", 5000);
	set("daoxing", 10000);

        set("attitude", "friendly");

        set("chat_chance_combat", 50 );
        set("inquiry", ([
"Цʲô": "ʦ���ս���һ�����л�λ������������\n",
"���л�λ": "��ʦ��˵���԰��˴���Զ�����������Կ���\n",
"����": (: try_me :),
]) );
        setup();

}
string try_me(object me)
{	me = this_player();
        command ("say ����Ҳ�ã�����");

message_vision("𫲻��˫����$Nͷ��һ�������˾����$N�Ժ�֮�к�����˳�ȥ������\n",
me);
	me->move("/d/lingtai/hill");
	return "���ˣ�����ô�����ˣ�";
}

void init()
{
        object ob;

        ::init();
        set("chat_chance", 10);
        set("chat_msg", ({
            (: random_move :)
        }) );
}

�
