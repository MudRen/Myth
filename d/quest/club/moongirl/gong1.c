//�������¹�
//by junhyun@SK

inherit ROOM;

void create ()
{
        set ("short", "��ǰ�㳡");
        set ("long", @LONG

������һƬ�����Ĺ㳡�����¹����˾���������ۻᱱ���
��Ρ���Ǭ�¹������������¹�������������䳡��������
ÿ��������¹�������ı��䳡�������㳡��������裬
���������һ�����ϵľ���
LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
       "north" : __DIR__"moon1",
       "east" : __DIR__"wuchang",
       "west" : __DIR__"kantai", 
       "south" : __DIR__"door",
        ]));

        set("objects", 
        ([ //sizeof() == 1
        ]));

        set("outdoors", "changan");
        setup();
        replace_program(ROOM);
}

