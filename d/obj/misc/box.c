//Cracked by Roath

inherit ITEM;
void create() {
        set_name("����", ({ "deposit box","box" }) );
        set_weight(100);
        set_max_encumbrance(10000);
        if( clonep() )                 set_default_object(__FILE__);
        else {
                set("unit", "ֻ");
                set("value", 500);
        }
      set("max_items",1);
}
int is_container() { return 1; }

void init() {
  add_action("do_put","put");
  add_action("do_mark","mark");
}

int do_mark(string arg) {
    

   if (!arg) {
     if (!query("mark"))  write("�����ϻ�û���κμǺš�\n");
       else write("�����Ͽ��ţ� "+query("mark")+"\n");
     return 1;
   }

   if (query("owner")) return notify_fail("���Ҷ���\n");

   if (query("mark")) write("�㽫������ԭ���ļǺ�Ϳ����\n");
   write("���ں����Ͽ��ϡ�"+arg+"����������\n");
   set("mark",arg);

   return 1;
}




int do_put(string arg)
{
    string target, item;
    object dest, *inv,me=this_player();

    if(!arg) return 0;

    if( sscanf(arg, "%s in %s", item, target)!=2 )
           return 0;

    dest = present(target, me);
    if (dest!=this_object()) return 0;

    inv = all_inventory(dest);
    if (inv && sizeof(inv)) {
       write("�������Ѿ��ж����ˡ�\n");
       return 1;
    }
    return 0;
}
