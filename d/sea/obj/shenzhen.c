inherit ITEM;

void create()
{
        set_name("��������", ({ "shenzhen" }));
	set_weight(100000);
	if (clonep())
                set_default_object(__FILE__);
        else {
		set("long", "��˵�еĶ������롣����ϸ��ȥ�����ƺ���Щ����ͷ�����˲����е�һЩ���ɡ�\n");
		set("unit", "��");
set("value", 1000);
		set("material", "iron");
		}
	setup();
}



