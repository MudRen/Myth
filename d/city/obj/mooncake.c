inherit ITEM;
inherit F_FOOD;

void create()
{
        
	switch (random(8))
  {
	case 0:{
	set_name("�����±�", ({"moon cake", "mooncake", "yue bing", "yuebing"}));
	break;}
	case 1:{
	 set_name("��ɳ�±�", ({"moon cake", "mooncake", "yue bing", "yuebing"}));
       break;}
	case 2: {
	set_name("˫���±�", ({"moon cake", "mooncake", "yue bing", "yuebing"}));
       break;}
	case 3: {
	  set_name("�����±�", ({"moon cake", "mooncake", "yue bing", "yuebing"}));
       break;}
	case 4: {
	  set_name("�����±�", ({"moon cake", "mooncake", "yue bing", "yuebing"}));
	break;}
        case 5: {
          set_name("Ҭ���±�", ({"moon cake", "mooncake", "yue bing", "yuebing"}));
        break;}
        case 6: {
          set_name("�����±�", ({"moon cake", "mooncake", "yue bing", "yuebing"}));
        break;}
        case 7: {
          set_name("���ǰ���", ({"moon cake", "mooncake", "yue bing", "yuebing"}));
        break;}

	}
        set_weight(1000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "һ�龫�����±�������ӡ�š�������֡���ͼ����\n");
                set("food_remaining", 4);
                set("food_supply", 50);
		set("value", 1000);
		set("no_sell","��ȥ���ҷ������𣿣���\n");
        }
}

