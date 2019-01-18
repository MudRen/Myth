//Cracked by Roath
// lianwuch1.c
// written by kittt

inherit ROOM; 
void init();
int do_da(string arg);
int do_yao(string arg);

void create() 
{
	set("short", "���䳡"); 
	set("long",@LONG
��������ݵ����䳡���䳡�м���ż���ľ׮(muzhuang)��
�м������ھ۾�����ش��š�Ҳ�����ڻ����д裬����������
���ġ��Ա߻��и���ͷ��ָ�����ǡ�    
LONG);

	set("exits",([
		"south" : __DIR__"shibanlu3",
		])); 
	set("item_desc",([
		"muzhuang":		"���������õ�ľ׮�����Դ�(da)��ҡ(yao)��\n"
		]));
	set("objects",([
//		__DIR__"npc/zhaowushi":1,
		]));
		
	setup(); 
} 

void init()
{
	add_action("do_da","da");
	add_action("do_yao","yao");
}

int do_da(string arg)
{
	int pot;
	object ob=this_player();
	
	if((!arg)||(arg!="muzhuang"))
		return notify_fail("��Ҫ��ʲô��\n");
	if(ob->query_skill("unarmed",1)>50)
		return notify_fail("���ȭ��ʮ�־�տ�����������Ѿ��ò���ʲô������\n");
	
	pot=random(10);
	if(pot)
	{
		ob->improve_skill("unarmed", pot);
		ob->receive_damage("kee",10);
		message_vision("$N���������������һȭ��ľ׮��ȥ��\n",ob);
		tell_object(ob,"��ԡ�����ȭ���������˽⡣\n");
		return 1;
	}
	ob->receive_damgae("kee",5);
	message_vision("$N������˫ȭ������ľ׮һ�����ҡ�\n",ob);
	return notify_fail("������˰���ȭͷ��ʲô������û�С�\n");
}

int do_yao(string arg)
{
	int pot;
	object ob=this_player();
		
	if((!arg)||(arg!="muzhuang"))
		return notify_fail("��Ҫҡʲô��\n");
	if(ob->query_skill("parry",1)>50)
		return notify_fail("��ָ��ҡ�ⶫ��ҡ������ɲ⡣\n");
		
	pot=random(10);
	if(pot)
	{
		message_vision("$N˫�ֱ��������ص�ҡ��ľ׮��\n",ob);
		ob->improve_skill("parry",pot);
		ob->receive_damage("kee",10);
		tell_object(ob,"��ԡ������мܡ������˽⡣\n");
		return 1;
	}
	ob->receive_damage("kee",5);
	message_vision("$N����ľ׮��ҡһ����Ҳ��֪�����ʲô��\n",ob);
	return notify_fail("��ҡ�˰����ľ׮������ò���ʲô������\n");
}
