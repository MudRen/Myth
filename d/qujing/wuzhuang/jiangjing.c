//Cracked by Roath
inherit ROOM;

void create ()
{
	set ("short", "������");
	set ("long", @LONG

������ƽʱ��Ԫ��������е�ʿ����ʱ���ã�������һ��������
ǰ��������ʮ��������档��������û���������裬����Ԫ����
Ϊ�����������Ϊ��
LONG);

	set("exits", 
	([ //sizeof() == 4
		"south" : __DIR__"wpiandian",
		"eastup": __DIR__"yanzhen",
	]));
	
	set("objects", 
	([ //sizeof() == 1
		//__DIR__"npc/qingfeng" : 1,
  "/obj/zhangmen/wuzhuang" : 1,
	]));


//	set("outdoors", "wuzhuang");

	setup();
	call_other("/obj/board/jiangjing_b", "???");
}
