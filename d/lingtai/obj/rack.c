inherit ITEM;

void create()
{
        set_name("������", ({ "rack" }) );
        set_weight(500000);
        set_max_encumbrance(40000);
        if( clonep() ) {
                object a,b,c,d,e;
                  seteuid(getuid());
                if(a=new("/d/obj/weapon/stick/qimeigun"))
                  a->move(this_object());

                  seteuid(getuid());
                if(d=new("/d/obj/weapon/stick/qimeigun"))
                  d->move(this_object());

                  seteuid(getuid());
		if(b=new("/d/obj/weapon/stick/bintiegun"))
		  b->move(this_object());

                  seteuid(getuid());
                if(e=new("/d/obj/weapon/stick/bintiegun"))
                  e->move(this_object());

                  seteuid(getuid());
		if(c=new("/d/obj/armor/niupi"))
		  c->move(this_object());
                set_default_object(__FILE__);
        } else {
                set("unit", "��");
                set("long", "����һ��Ѱ���ļ��ӣ����������ѷ�һЩ���\n");
                set("value", 0);
        }
}

int is_container() { return 1; }

