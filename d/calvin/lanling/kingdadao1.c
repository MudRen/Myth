//shulin ����

inherit ROOM;

void create ()
{
        set ("short", "������");
        set ("long", @LONG

������ͨ������ʹ���Ψһ��·,Ҳ��������Ϊ������·.
·��������������,���ﻨ��,�ò�����.����·��ÿ���
���³�һ�ϰ����Ǳ���ֹ�߶�,����·��ɾ�.��Ϊ����
�ʵ�Ҫͨ����Ѳ������� ... ...

LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 8
                 "north" : "/d/calvin/lanling/center",
                "south" : "/d/calvin/lanling/kingdadao2",
        ]));

        set("objects", 
        ([ //sizeof() == 1
        ]));

        set("outdoors", "changan");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
