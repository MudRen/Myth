// bishuizhou.c

inherit ITEM;

void create()
{
        set_name("��ˮ��", ({"bishui zhou","zhou"}));
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
	set("long",
	"һ��СֽƬ������д�š���ˮ�䡱�����֣���֪����ʲô��û�С�\n");
        set("material", "paper");       
        }
}


