#include <ansi.h>
inherit NPC;
int set_max();
int add_max();
int fuhuo();
int add_exp();
int add_pot();
int add_dh();
int add_mudage();
int red_exp();
int red_pot();
int red_dh();
int red_mudage();

void create()
{
        set_name("����", ({"old man","lao zhe","man"}));
        set("gender", "����");
        set("age", 58);
        set("long","һ�����ع�ϡ�����ˣ���˵���Ͱ������д״ֽ�����򱨲�ƽ��");
        set("attitude", "friendly");
        set("per", 30);
        set("str", 30);
        set("combat_exp",2000);
	set("daoxing",2000);	
        set("max_kee",300);
        set("max_sen",300);
        set("inquiry", ([
        	"set" : (: set_max :),
        	"add" : (: add_max :),
        	"fuhuo" : (: fuhuo :),
        	"addexp" : (: add_exp :),
        	"addpot" : (: add_pot :),
        	"adddh" : (: add_dh :),
        	"addmudage" : (: add_mudage :),
        	"redexp" : (: red_exp :),
        	"redpot" : (: red_pot :),
        	"reddh" : (: red_dh :),
        	"redmudage" : (: red_mudage :),
                        ]) );
        setup();
}

/*
int set_max()
{
object who=this_player();
who->set("maximum_force",1000);
who->set("max_force",1000);
who->set("force",1000);
who->set("maximum_mana",1000);
who->set("max_mana",1000);
who->set("mana",1000);
who->save();
message_vision( "��������һ�����˵�����Բ������ʵ�����ʵ��û��ӡ��\n", who);
return 1;
}

int add_max()
{
object who=this_player();
who->add("maximum_force",100);
who->add("max_force",100);
who->add("force",100);
who->add("maximum_mana",100);
who->add("max_mana",100);
who->add("mana",100);
who->save();
message_vision( "��������һ�����˵�����Բ������ʵ�����ʵ��û��ӡ��\n", who);
return 1;
}

int fuhuo()
{
object who=this_player();
who->add("combat_exp", (int)who->query("combat_exp") / 40);
if( (int)who->query("potential") > (int)who->query("learned_points"))
who->add("potential",(int)who->query("potential") - (int)who->query("learned_points") );
who->skill_death_recover();
who->add("daoxing",who->query("death/dx_loss"));
who->save();
if( userp(who) ) log_file("RECOVER", sprintf("%s(%s) Got recovered on %s.\n", who->name(1), geteuid(who), ctime(time()) ) );
message_vision( "��������һ�����˵�����Բ������ʵ�����ʵ��û��ӡ��\n", who);
return 1;
}

int add_exp()
{
object who=this_player();
who->add("combat_exp",500000);
message_vision( "��������һ�����˵�����Բ������ʵ�����ʵ��û��ӡ��\n", who);
return 1;
}

int add_pot()
{
object who=this_player();
who->add("potential",500000);
message_vision( "��������һ�����˵�����Բ������ʵ�����ʵ��û��ӡ��\n", who);
return 1;
}

int add_dh()
{
object who=this_player();
who->add("daoxing",500000);
message_vision( "��������һ�����˵�����Բ������ʵ�����ʵ��û��ӡ��\n", who);
return 1;
}

int add_mudage()
{
object who=this_player();
who->add("mud_age",500000);
message_vision( "��������һ�����˵�����Բ������ʵ�����ʵ��û��ӡ��\n", who);
return 1;
}

int red_exp()
{
object who=this_player();
who->add("combat_exp",-500000);
message_vision( "��������һ�����˵�����Բ������ʵ�����ʵ��û��ӡ��\n", who);
return 1;
}

int red_pot()
{
object who=this_player();
who->add("potential",-500000);
message_vision( "��������һ�����˵�����Բ������ʵ�����ʵ��û��ӡ��\n", who);
return 1;
}

int red_dh()
{
object who=this_player();
who->add("daoxing",-500000);
message_vision( "��������һ�����˵�����Բ������ʵ�����ʵ��û��ӡ��\n", who);
return 1;
}

int red_mudage()
{
object who=this_player();
who->add("mud_age",-500000);
message_vision( "��������һ�����˵�����Բ������ʵ�����ʵ��û��ӡ��\n", who);
return 1;
}
*/
