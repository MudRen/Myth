//Cracked by Roath
// lianwuch2.c
// written by kittt

inherit ROOM;

void init();

int do_tiao(string arg);

void create() 
{
	set("short", "���䳡"); 
	set("long",@LONG
��������ݵ����䳡����Ҹ������ģ�����������������
�������������������˺���䤱�����һ��ɳ��(keng)����������
�Աߵ�һλ��ͷ����ؿ��ţ���ʱ˵�����䡣
LONG);
	
	set("item_desc",([
		"keng":		"һ��ɳ�ӣ���������(tiao)����\n"
		]));
	set("exits",([
		"south" : __DIR__"shibanlu4",
		]));
	set("objects",([
//		__DIR__"npc/liwushi":	1,
		]));
	
	setup(); 
}
 
void init()
{
	add_action("do_tiao","tiao");
}

int do_tiao(string arg)
{
	object ob=this_player();
	
	if((!arg)||(arg!="keng"))
		return notify_fail("��Ҫ��ʲô��\n");
	if(ob->query_skill("dodge",1)>50)
		return notify_fail("��ָ����ɳ������������ɲ⡣\n");
	ob->improve_skill("dodge", random(3));
	ob->receive_damage("kee",10);
	message_vision("$N��ɳ����������ȥ��\n",ob);
	return 1;
}
