// midao3.c
// by lestat

inherit ROOM;

void create()
{
        set("short", "����ͨ��");
        set("long", @LONG
����һ���ֳ��ֺڵ�����ͨ������Լ���Ըо��������Ǳ������Ӳ��ʯ
�ڣ���ʲô�˿��������ֻ���Կ�������ǰ����
LONG );
	set("exits", ([
		"south" : __DIR__"midao2",
		"out" : "/d/city/center",
	]));
	set("no_clean_up", 0);
	setup();
}

int valid_leave(object me,string dir)
{
        if(dir=="out") 
	 tell_object(me,"���߳�������ͨ�������صس����ڳ�����ʮ�ֽ�ͷ��\n");
	 return ::valid_leave(me,dir);
}

