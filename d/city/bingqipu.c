//Cracked by Roath
//changan city

inherit ROOM;

void create ()
{
        set ("short", "������");
        set ("long", @LONG

��һ���žͿ����������ϰ��Ÿ��ֱ��������ϰٽ��صĴ󵶵������
�ӵķɻ�ʯ����Ӧ�о��С�Ů�ϰ�����Ӣ������Զ��СŮ����Ҳ����
Զ�ھֶ��ϰ壬����������ü��
LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
                "north" : __DIR__"qinglong-e1",
        ]));

        set("objects", 
        ([ //sizeof() == 4
"/obj/boss/city_xiaoxiao" : 1,
//          "/quest/song/guanshi": 1,
        ]));


//        set("outdoors", "changan");
	set("no_clean_up", 0);
        setup();
	replace_program(ROOM);
}

