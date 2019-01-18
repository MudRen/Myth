//Cracked by Roath
// teller.c
//cglaem...12/16/96.

inherit NPC;

string suanming(object me);
string suan_fuyuan(object me);

void create()
{
        set_name("Ԭ�س�", ({"yuan shoucheng","yuan"}));
        set("title","��������");
        set("gender", "����" );
        set("age", 55);
        set("class","taoist");
        set("long", "��֪��������������飮��������û�в���ʶ���ġ�\n");
        set("combat_exp", 8000);
        set("daoxing", 80000);

        set("attitude", "peaceful");
        set_skill("unarmed", 10);
        set_skill("dodge", 20);
        set_skill("parry", 20);
        set_skill("literate", 50);
        set_skill("spells", 50);
        set("per", 15);
        set("max_kee", 350);
        set("max_gin", 300);
        set("max_sen", 300);
	set("max_mana", 200);
	set("mana", 200);
	set("mana_factor", 5);
        setup();
        carry_object("/d/obj/cloth/choupao")->wear();
}

void init()
{
        object ob;

        ::init();
        set("chat_chance", 10);
        set("inquiry", ([
                "name" : "С����Ԭ���سϣ������ٺ٣����ⳤ��һ������С�б�����\n",
                "here" : "��û������������ط��������µ�һ�������ڡ�\n", 
	    "��Ե" : (: suan_fuyuan :),
	    "����" : (: suanming :),
	    "����" : (: suanming :),
	    "suanming" : (: suanming :),
	 ]) );

        set("chat_msg", ({
	    "Ԭ�سϻ��˻����ϵĹ𻨾ƴ�Ц����������û���ë�������Ǻõ������\n",	
                "Ԭ�س��������´������㼸�ۡ�\n",
                "Ԭ�س�������ü��һ��������ֹ�����ӡ�\n",
                "Ԭ�س��������������������һ�£����������������\n�͹����û�����Ķ����þ���\n",
                (: random_move :)
        }) );
}


string suan_fuyuan(object me)
{
       int my_level;

       string *levels = ({
         "ù�����죬ˡ����ֱ�ԣ�Ѫ��֮�ֲ�Զ�ӣ�\n",
         "ӡ�÷�����������������\n",
         "�˵��пɡ�\n",
         "������Ե��ǳѽ����\n",
         "���Ƕร����֮�ˡ�\n",
         "����������Ե����ϲ����ϲ��\n",
         "���Ǹ��綫�����ٱ���ɽѽ��\n",
          });

        me = this_player();
        my_level=(me->query("kar")+me->query("donation/1000000"))/5-2;

        if( !me->query_temp("suanming/paid") )
        {
                if( me->query_temp("suanming/asked") ) 
                {
                        message_vision("Ԭ�سϱ����۾�������$N�ˡ�\n", me);
                        return "��������һ����ɫ���㣬��֪�����ܷ������\n";
                }
                else
                {
                        me->set_temp("suanming/asked", 1);
                        message_vision("Ԭ�س��ϳ������ɿ��˼�����\n", me);
                        return "����������������й¶����\n";
                }
        }
        else
        {
                me->delete_temp("suanming");
                message_vision("Ԭ�س϶�$N�����������Ҷ����ˣ�˵����ָ���˼��㡣\n", me);
                if(my_level<0 || my_level>6 )
                        return "��֣�"+RANK_D->query_respect(me)+
                            "����ʮ�ֹ��죬������Ϊ�������㲻����������\n";
                else
                   return RANK_D->query_respect(me)+levels[my_level];
        }
}

string suanming(object me)
{
        me = this_player();

        if( !me->query_temp("suanming/paid") )
        {
                if( me->query_temp("suanming/asked") ) 
                {
                        message_vision("Ԭ�سϱ����۾�������$N�ˡ�\n", me);
                        return "��������һ����ɫ���㣬��֪�����ܷ������\n";
                }
                else
                {
                        me->set_temp("suanming/asked", 1);
                        message_vision("Ԭ�س��ϳ������ɿ��˼�����\n", me);
                        return "����������������й¶����\n";
                }
        }
        else
        {
                me->delete_temp("suanming");
                message_vision("Ԭ�س϶�$N�����������Ҷ����ˣ�˵����ָ���˼��㡣\n", me);
                if(me->query("life/live_forever"))
                        return "ʧ����ʧ����ԭ��"+
			    RANK_D->query_respect(me)+
			    "���������⣬���������У�����������������ˣ�\n";
                else if(me->query("age")<16)
		    return RANK_D->query_respect(me)+
			"���᳤�����꣬ǰ;����������\n";
		else
                   return RANK_D->query_respect(me)+"��"+
		       me->query("life/life_time")+"������١�\n";
        }
}

int accept_object(object me, object ob)
{
	object nowords;

        if( (string)ob->query("name")=="�𻨾ƴ�" )
        {
		command("u&me " + me->query("id"));
       		command("say ��λ" + RANK_D->query_respect(me) + "���Ǹ���ͶԵ��\n������Ҳ��һ��С��˼����Ц�ɡ�\n");
	        carry_object("/d/obj/book/nowords");
	        command("give nowords to " + me->query("id"));
       		return 1;
        }
        else if( (string)ob->query("name")=="��ɫ����" )
        {
                message_vision("Ԭ�س�����ѻ��ض�$N������л"+RANK_D->query_respect(me)+"����������Ҫ�������ʲô�����������ʣ�\n", me);
                me->set_temp("suanming/paid", 1);
                return 1;
        }
        else
        {
            command("say ���ҵ����ҵ���������̫�����ˡ�");
            return 1;
        }
}
