//Cracked by Roath
// ctxiaosi.c ����С˹
// writen by kittt

#include <ansi.h>

inherit NPC;

int ask_food();
int ask_water();
int greeting(object ob);
void init();

void create()
{
	set_name("����", ({"pu ren","pu","ren"}));
	set("gender", "����");
	set("age", 23);
	set("long", 
	"���������ר���ͷ������ˡ� \n" );
	
	set_skill("unarmed", 10);
	set_skill("dodge", 10);
      set_temp("apply/attack", 10);
	set_temp("apply/defense", 10);
	set("combat_exp", 1000);
 	set("inquiry", ([
				"ʳ��":		(:ask_food:),
				"ˮ":		(:ask_water:)
])); 	
	setup();
	
	carry_object(__DIR__"obj/cloth")->wear();
}


int ask_food()
{
	mapping* food;
	mapping food1;
	object fd,me=this_player();
	object ob=this_object();

    if(!this_player()->query("wuguan/join"))
	{
		tell_object(me,"�����������ģ�\n");
		return 1;		
	}
	
	if ((present("baozi",me)
		|| present("mifan",me)
		|| present("jitui",me)))
	{
		message_vision("���˰���$Nһ�ۣ������Ȱ����ϵĳ�����˵��\n",me);
		return 1;
	}
	if ((objectp(present("baozi", environment(ob)))
		||  objectp(present("mifan", environment(ob)))
		|| objectp(present("jitui", environment(ob)))))
	{
		command("say ˭֪���вͣ����������࣡���Ȱѵ��ϵ�ʳ��������Ե��ɡ�");
		return 1;
	}
	
	food=({
		([
			"object":		__DIR__"obj/baozi",
			"message":		"���˸�$Nһ�����ӡ�\n"]),
		([	
			"object":		__DIR__"obj/mifan",
			"message":		"���˸�$Nһ���׷���\n"]),
		([	
			"object":		__DIR__"obj/jitui",
			"message":		"���˸�$Nһ�����ȡ�\n"])
		});
	food1=food[random(sizeof(food))];
	fd=new(food1["object"]);
	fd->move(this_player());
	message_vision(food1["message"],this_player());
	return 1;
}

int ask_water()
{
	object tea,me=this_player();
	
    if(!this_player()->query("wuguan/join"))
	{
		tell_object(me,"�����������ģ�\n");
		return 1;
	}
    if ( objectp(present("tea", environment(this_object())))){ 
        command("say ���˷��ˣ����Ȱѵ��ϵĲ�ȵ��ɡ�");
        return 1;
             } 

	if (present("tea",me)){
		message_vision("���˰���$Nһ�ۣ����������л�����Ҫ�����Ĳ�����ѽ��\n",me);return 1;
	}
	tea=new(__DIR__"obj/tea");
	tea->move(this_player());
	message_vision("���˽���$Nһ����衣\n",this_player());
	return 1;
}
void init()
{
        object ob;
         ::init();
if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
       } 
}

int greeting(object ob)
{
	if(environment(ob)!=environment(this_object()))
		return 0;
	command("say �����������"HIY"(ask pu ren about ʳ��)"NOR"Ҫʳ�"HIY"(ask pu ren about ˮ)"NOR"Ҫ�ȵġ�");
	return 1;
}
