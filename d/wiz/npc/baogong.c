//baogong.c

inherit NPC;

void create()
{
        set_name("����", ({ "baogong" }));
        set("long", "������˽�ڰ����������������㲻�ɵõ����ľ���˫�ȷ���\n");
        set("gender", "����");
        set("age", 50);
        set("attitude", "friendly");
        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("dex", 30);
        set("per" ,10);
        set("combat_exp", 50000);

        setup();
        carry_object("/d/obj/cloth/xianpao")->wear();
}

void init()
{       
        object ob=this_player();
	string id;
	object me=this_object();
        ::init();
	if (!wizardp(ob)) 
	{
	 command("chat* ֻ��"+me->query("name")+"һ�����ȣ�"+ob->query("name")+"������"+ RANK_D->query_rude(ob)+"���������Ҵ�ʵ������\n");
	 me->set("id",getuid(ob));
	 me->set("name",ob->query("name"));
	 command("chat* "+ob->query("name")+
	   "ϥ��һ����ͨһ�����ڵ��ϣ�������...����������������������...үү������\n");
	 me->set("id","baogong");
	 me->set("name","����");
	 command("chat* "+me->query("name")+"һ����ߵ�������������"+RANK_D->query_rude(ob)+"���Ҵ�����Σ�\n");
	 ob->set("startroom","/d/wiz/gongtang");
	 ob->move("/d/wiz/punish");
	 }
}


