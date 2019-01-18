// teller.c
//cglaem...12/16/96.

inherit NPC;

void create()
{
        set_name("Ԭ�س�", ({"teller","yuan"}));
        set("title","��������");
        set("gender", "����" );
        set("age", 55);
        set("class","taoist");
        set("long", "��֪��������������飮��������û�в���ʶ���ġ�\n");
        set("combat_exp", 1000);
        set("attitude", "peaceful");
        set_skill("unarmed", 10);
        set_skill("dodge", 20);
        set_skill("parry", 20);
        set_skill("literate", 50);
        set_skill("spells", 50);
        set("per", 15);
        set("max_kee", 250);
        set("max_gin", 300);
        set("max_sen", 300);
        setup();
        carry_object("/d/lingtai/obj/cloth")->wear();
}

void init()
{
        object ob;

        ::init();
        set("chat_chance", 10);
        set("inquiry", ([
                "name" : "С����Ԭ���س�...�ٺ٣����ⳤ��һ������С�б�����\n",
                "here" : "��û������������ط��������µ�һ�������ڡ�\n", 
	    "����" : "��Ȼ������ɡ��ҵľ���ַ��ˣ�����ȥ��һ����\n",
	    "����" : "��Ȼ������ɡ��ҵľ���ַ��ˣ�����ȥ��һ����\n",
	 ]) );

        set("chat_msg", ({
	    "Ԭ�سϻ��˻����ϵĹ𻨾ƴ�Ц����������û���ë�������Ǻõ������\n",	
                "Ԭ�س��������´������㼸�ۡ�\n",
                "Ԭ�س�������ü��һ��������ֹ�����ӡ�\n",
                "Ԭ�س��������������������һ�£����������������\n�͹����û�����Ķ����þ���\n",
                (: random_move :)
        }) );
}

int accept_object(object me, object ob)
{
	object nowords;

     if ((string)ob->query("name")!="�𻨾ƴ�") {
            command("say ���ҵ����ҵ�...��̫�����ˡ�");
	    command("give " + ob->query("id") + "to " + me->query("id"));
            return 1;
        }
        else {
		command("touch " + me->query("id"));
       		command("say ��λ" + RANK_D->query_respect(me) + "���Ǹ���ͶԵ��\n������Ҳ��һ��С��˼����Ц�ɡ�\n");
	        carry_object("/d/ourhome/obj/nowords");
	        command("give nowords to " + me->query("id"));
       		return 1;
        }
}


