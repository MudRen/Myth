//����

inherit ROOM;

void create ()
{
        set ("short", "�������");
        set ("long", @LONG

��һ���ž��ŵ�һ������,�����ѵõĺõط���
ƽʱ�������ǻ㼯�źܶ������,���Ǵ���
׼���½츰���ǸϿ������.���ﲼ�ֵ��Ŵ�.
LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
    "west" : "/d/calvin/lanling/jie6",
        ]));

        set("objects", 
        ([ //sizeof() == 1
"/obj/boss/lanling_booker.c" : 1,
        ]));

//        set("outdoors", "changan");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
