inherit ITEM;

void create()
{
	set_name("����ָ��",({"xiaqi zhinan","xiaqi","zhinan"}) );
	set("long","���� read zhinan �Ķ�������Ʒ��ͤ���塣\n");
	set_weight(5);
	set("unit","��");
	set("value",100);
}

void init()
{
	add_action("do_read","read");
}

int do_read(string arg)
{
	object me = this_player();
	string msg = "��ӭ��Ʒ��ͤ�����壡\n" +
"
Ʒ��ͤ:�ӳ�������->s->e->e->nu->enter

��������������Χ��������壬���¸���������Ĳ��裺
һ�����Һö��֣�Ȼ��ֱ��� sit black �� sit white ������
����ʹ�� new ��ʼһ���µ���֣�new [-5] [-b(numbers)] [-h(numbers)]
    ���� -5 �����������壬��ѡ��Ϊ��Χ�壻
����-bָ���������̵Ĵ�С��
    -hָ�����ӵ���Ŀ��
�������磺
����Χ�壺new
����ʮ���ʮ��������壺new -5 -b15
�����þ���Χ�壺new -h9
����ʹ�� play �������壺���� play d4 �ȵȡ�
�ġ�ʹ�� refresh�ۿ����̡�
�塢ʹ�� undo ���塣(Ŀǰֻ�ṩ������Ļ��幦�ܡ�)

";
	if(arg=="zhinan" || arg=="xiaqi zhinan") {
		tell_object(me,msg);
		return 1;
	}
	 else return 0;
}

