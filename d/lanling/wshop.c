//����

inherit ROOM;

void create ()
{
        set ("short", "װ����");
        set ("long", @LONG

��һ���žͿ����������ϰ��Ÿ��ֱ��������ϰٽ��صĴ󵶵������
�ӵķɻ�ʯ����Ӧ�о��С�Ů�ϰ�����Ӣ������Զ�Ķ�Ů����Ҳ����
Զ�ھִ��ϰ壬����������ü��
LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
//              "east" : "/u/calvin/����/����/������6",
        ]));

        set("objects", 
        ([ //sizeof() == 1
//                 "/d/obj/����/װ���ϰ�" : 1,
        ]));

//        set("outdoors", "changan");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
