//sgzl

inherit NPC;

void create()
{
        set_name("�Ž���", ({"ba jiangjun","ba","monkey"}));
        set("title","����ɽ��");
        set("gender", "����" );
        set("age", 35);
        set("class","taoist");
        set("long", "һֻ���˾���ͨ��Գ��\n");
        set("combat_exp", 60000);
  set("daoxing", 30000);

        set("attitude", "peaceful");
        set_skill("unarmed", 60);
        set_skill("dodge", 60);
        set_skill("parry", 60);
        set_skill("spells", 60);

        set("max_kee", 450);
        set("max_gin", 450);
        set("max_sen", 450);

        set("max_force", 600);
        set("force", 600);
        set("force_factor", 30);
	set("max_mana", 400);
	set("mana", 400);
	set("mana_factor", 20);
        setup();
}

void init()
{
        object ob;

        ::init();
        set("chat_chance", 3);
        set("inquiry", ([
                "name" : "�Ҿ��ǻ���ɽˮ�����󽫰Ž�����\n",
                "here" : "����ǻ���ɽ��\n", 
                "����" : "�٣��ҼҴ������ǻ���ɽˮ����������\n",
                "weapon" : "��ҵı�������ȥ������͵Щ���ҼҴ����ı��������Ҫ��Щ�������ھ����ˡ�\n", 
                "����" : "��ҵı�������ȥ������͵Щ���ҼҴ����ı��������Ҫ��Щ�������ھ����ˡ�\n", 
 
	 ]) );

        set("chat_msg", ({
	    "�Ž���˵�����ҼҴ��������쳣�������Ϻõı�����\n",	
            "�Ž������������˵���ҵ�֪�����ط��ɸ�Щ��������\n",
        }) );
}

�