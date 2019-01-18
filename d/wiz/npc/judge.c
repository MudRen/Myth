// judge.c

#include <login.h>
#include <ansi.h>

inherit NPC;

int in_ask, answer;

void create()
{
	set_name("���й�", ({ "judge" }) );
	set("short", "ר�ŶԸ������˵�" HIY "���й�" NOR "(judge)" );
	set("long",
		"����һλ�������Ƿ��ǻ����˵����й٣��������(answer)�������������\n"
		"�����������ա�\n");

	set("gender", "����");
	set("age", 40);

	set("str", 100);
	set("int", 100);
	set("cor", 100);

	set("combat_exp", 9000000);
	set("score", 0);

	set_temp("apply/attack", 200);
	set_temp("apply/damage", 500);

	setup();
	carry_object("/d/obj/cloth/xianpao")->wear();

	in_ask = 0;
}

void init()
{
	::init();
	if( !query_heart_beat(this_object()) ) set_heart_beat(1);
	add_action("do_answer", "answer");
}

void chat()
{
	int a, b, c;
	string oper;
	object *nv,env;
         
        env = environment(this_object());

	if( in_ask ) return;
        if ( random(20)>10 ){
             for(a=0; a<sizeof(nv); a++)
                      if( interactive(nv[a]) && !(wizardp(nv[a])) ) nv[a]->start_busy(20);
             return;
        }
 
	delete_temp("wrong");
	a = random(100) + 1;
	b = random(100) + 1;
	switch(random(5)) {
		case 0: 
			answer = a + b;
			oper = chinese_number(a) + "����" + chinese_number(b)+ "���ڶ��٣�";
			break;
		case 1: 
			answer = a - b;
			oper = chinese_number(a) + "��ȥ" + chinese_number(b)+ "���ڶ��٣�";
			break;
		case 2: 
			if( a * b < 200 ) {
				answer = a * b;
				oper = chinese_number(a) + "����" + chinese_number(b)+ "���ڶ��٣�";
			} else {
				answer = (a * b) % 10;
				oper = chinese_number(a) + "����" + chinese_number(b)+ "����λ�����ڶ��٣�";
			}
			break;
		case 3: 
			answer = a % b;
			oper = chinese_number(a) + "����" + chinese_number(b)+ "���ڶ��٣�";
			break;
		case 4:
			oper = chinese_number(a) + "��" + chinese_number(b)+ "����������Ƕ��٣�";
			if( b < a ) { c = b; b = a; a = c; }
			while( a > 1 && b%a > 1 ) {
				c = a;
				a = b%a;
				b = c;
			}
			answer = b%a == 1 ? 1 : a;
			break;
	}
	command("say " + oper + "�����ڶ�ʮ��������(answer)��");
        nv = all_inventory(env);
        for(a=0; a<sizeof(nv); a++)
                if( interactive(nv[a]) && !(wizardp(nv[a])) ) nv[a]->start_busy(20);
	in_ask = 1;
	call_out("say_answer", 20);
}

void say_answer()
{
	command("say ��ô�򵥶����᣿�𰸵���" + chinese_number(answer) + "��");
	in_ask = 0;	
}

int do_answer(string arg)
{
	string s;
	int ans;

	if( !in_ask ) return notify_fail("��������һ�⡣\n");
	if( !arg ) return notify_fail("����ش�һ�����֡�\n");

	message_vision( CYN "$N�����" + arg + "\n" NOR, this_player());
	
	if( sscanf(arg, "%d", ans)==1 ) {
		if( ans==answer ) {
			this_player()->add_temp("robot_check", 1);
			command("say ����ˣ�");
			command("pat " + this_player()->query("id") );
			remove_call_out("say_answer");
			in_ask = 0;
			if( this_player()->query_temp("robot_check") >= 3 ) {
				command("say �ܺã��㿴������������ˣ���������ˡ�\n");
                        this_player()->start_busy(1);

				if( stringp(s = this_player()->query_temp("old_startroom")) )
					this_player()->set("startroom", s);
				this_player()->delete_temp("robot_check");
				if( stringp(s = this_player()->query_temp("old_location")) )
					this_player()->move(s);
				else
					this_player()->move(START_ROOM);
			}
		} else {
			command("say ��");
			add_temp("wrong/" + this_player()->query("id"), 1);
			if( query_temp("wrong/" + this_player()->query("id")) > 3 ) {
				command("say " + this_player()->name() + "���ٸ����Ҳ°���ȥ���ɡ�\n");
				this_player()->receive_damage("kee", 100, this_object());
				this_player()->die();
			}
		}
	}
	return 1;
}
