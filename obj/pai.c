inherit ITEM;

void create()
{
        set_name("ͭ��", ({"tong pai", "pai"}));
        set_weight(100);
        if (clonep())
                set_default_object(__FILE__);
    else  {
           set("unit", "��");
           set("long", "һ��Сͭ�ƣ����滹���Ż���д���֣�\n");
	set("player", "bula"); 
          set("no_sell", 1);
        }
}


string long()
{
   string msg;

   if(!query_temp("long_1") )
          return query("long");

   msg = "һöͭ��\n",
   msg += "��д��" + query_temp("long_1") + "\n";

   return msg;
}
string player()
{ 	string msg;
	if(!query("player"))
	return query("player");
	msg = query("player");
return msg;
}
