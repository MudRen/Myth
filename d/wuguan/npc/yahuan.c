//Cracked by Roath
// yahuan.c Ѿ��
// writen by kittt

inherit NPC;

void create()
{
	set_name("СѾ��", ({"xiao yahuan", "xiao", "yahuan"}));
	set("gender", "Ů��");
	set("age", 15);
	set("long", 
	"һ�����ڴ�ɨԺ�ӵ�СѾ�������������㻹С\n"
	"���꣬���˾��úÿ����� \n" );
	set("shen_type", 1);
		 	
	setup();
	
	carry_object(__DIR__"obj/cloth")->wear();
}

