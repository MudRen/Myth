//shulin ����

inherit ROOM;

void create ()
{
        set ("short", "ǧѰ��");
        set ("long", @LONG

����һ���ƾɵ��߷�,������ò����,������������ĵ�ͼ
�����ܺ�,һʱҲû���ط���,����һֱ�����ڻ�����������
���ӡ�������ϰ��Ǹ�������,��˵���������Կ���״Ԫ��
������Ϊ�ò�����100���ƽ���Ϊ��Ʒ,����û��ѡ�ϡ�

LONG);
        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
       "east" : "/d/calvin/lanling/jie5",
        ]));

        set("objects", 
        ([ //sizeof() == 1
  "/obj/boss/lanling_mapman" : 1,
        ]));

//      set("outdoors", "changan");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
