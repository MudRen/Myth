//Cracked by Roath
inherit ITEM;

string *names = ({
        "��ë",
        "��ë",
        "��Ƥ",
        "��ʯͷ",
        "��֦",
        "������",
        "����Ƥ",
        "�Ʋ�ͷ",
        "��ë",
        "��Ƥ",
        "�Ӳ�",
        "�ù�����ǩ",
        "�ϱ�",
});

string *ids = ({
        "niao mao",
        "zhu mao",
        "zhu pi",
        "big stone",
        "shu zhi",
        "dead mouse",
        "xigua pi",
        "po butou",
        "ji mao",
        "suan pi",
        "zao cao",
        "used yaqian",
        "duan bi",
});

string *units = ({
        "��",
        "��",
        "��",
        "��",
        "��",   
        "��",
        "��",
        "��",
        "��",
        "��",
        "��",
        "��",
        "֧",
});

void create()
{
  int i = random(sizeof(names));
  set_name(names[i], ({ids[i]}));
  set("unit",units[i]);
  set("value",5);
  setup();
}
