//Cracked by Roath
inherit ROOM;
int block_cmd(string); 

void create ()
{
	set ("short", "���Ƹ�");
	set ("long", @LONG

���Ƹ�ӹ��е���ߴ������ϻ�����������麿������������˺�
��Ĺ�����Χ����������ƾ��������Զ�����¾�����ǰ��ɽ��
�巿¥�ᣬɽ����ʯ����������Ŀ��
LONG);

	set("exits", 
	([ //sizeof() == 4
		"down": __DIR__"yanzhen",
//    "master": "/d/wailijie/room/wzgmaster.c",
	]));
	
	set("objects", 
	([ //sizeof() == 1
		//__DIR__"npc/qingfeng" : 1,
		__DIR__"npc/zhenyuan" : 1,
	]));


	set("outdoors", "wuzhuang");
        set("no_fight", 1);   
        set("no_magic", 1);   

	setup();
}

void init() 
{
  add_action("block_cmd", "", 1); 
}

int block_cmd(string args) 
{
  string verb; 
  verb = query_verb(); 
  
  if (verb == "bian") return 1;
  if (verb == "cast") return 1;
  return 0; 
}
