//Creat by waiwai@2001/05/03

inherit NPC;

int play_chess();

void create()
{
        set_name("����", ({ "chess player", "player" }) );
        set("gender", "����" );
        set("age", 43);
        set("long", "һλʮ�����������ӣ�װ��������塣\n");
        set("str", 12);
        set("int", 28);
        set("combat_exp", 500);
        set("attitude", "friendly");
        set_skill("unarmed", 10);
        set_skill("dodge", 80);
        set_skill("throwing", 30);

        set("inquiry", ([
		"����" : (: play_chess :),
                "ALL" : (: play_chess :),
                "all" : (: play_chess :),
        ]) );

	setup();
        carry_object("/obj/cloth")->wear();
//	for(int i=1; i<=10; i++){
		carry_object("/d/city/npc/obj/chess")->wield();
//	}
}

int play_chess()
{       object chess;
        command("say Ҫ����һ�̣��ð���");
	if(random(100)<50)
	{
		command("say ���弼�����������Ϊ�����͸�����ö���ӷ���ɣ�");
        chess=new("/d/city/npc/obj/chess");
        chess->move(this_player());
        return 1;
	}
	command("say ���ó���!");
        return 1; 
}