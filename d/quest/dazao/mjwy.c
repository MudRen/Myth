//Created by kuku@sjsh 2003.2

inherit ROOM;

void create ()
{
        set ("short", "������Ӱ");
        set ("long", @LONG

����������������������ʦ��ס�ĵط�������������
��Թ���ϣ�����ʦ������Ҳ��������������������
���������ˡ�
LONG);

        set("exits", ([ /* sizeof() == 2 */             
                "north" : "/d/qujing/qinfa/jiedao5",
        ]));
        set("objects", ([  
                __DIR__"npc/zhuzaoshi" : 1,
        ])); 
        setup();
}
