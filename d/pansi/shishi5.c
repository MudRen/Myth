// shishi5.c
// by shilling 97.2

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
�����ǵ���ʯ�ҵ�������һ���ˣ�����ǰ��Ȼһ�������ﲼ�õû�����
�������ţ�ƽʵ��͸�Ÿ߹��ľ��������̫ʦ�Σ��Լ�ǽ�ϵ��ֻ���
͸��һ�ɷǷ�֮����
LONG );
	set("exits", ([
		"up" : __DIR__"shishi4",
	]));
	set("objects",([
		__DIR__"npc/zixia" : 1,
                "/d/pansi/obj/yinsuo":1, 
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
