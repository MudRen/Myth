inherit ITEM;

void create()
{
        set_name("ҩ��", ({ "cabinet" }) );
        set_weight(500000);
        set_max_encumbrance(40000);
        if( clonep() ) {
                object a,b,c,d,e;
                  seteuid(getuid());
              if(a=new("/d/obj/drug/wudiguo"))
                  a->move(this_object());

                  seteuid(getuid());
              if(b=new("/d/obj/drug/wudiguo"))
                  b->move(this_object());

                  seteuid(getuid());
              if(c=new("/d/obj/drug/wudiguo"))
                  c->move(this_object());

                  seteuid(getuid());
               if(d=new("/d/obj/drug/wudiguo"))
                  d->move(this_object());

                  seteuid(getuid());
              if(e=new("/d/obj/drug/wudiguo"))
                  e->move(this_object());
                set_default_object(__FILE__);
        } else {
                set("unit", "��");
                set("long", "����һ�ڷŵ�ҩ�ļ��ӣ��������һЩ���ĵ�ҩ��\n");
                set("value", 0);
        }
}

int is_container() { return 1; }

