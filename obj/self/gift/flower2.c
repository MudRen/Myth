// Created by aeddy@2003/05/05
// С������࣬��ò40����װ��

#include <armor.h>
inherit OTHERS;

void create ()
{
	set_name(HIW "ӣ������" NOR, ({ "prunus serrulata", "prunus", "serrulata" }));
	set_weight(100);
	set("long",
"ӣ��(sweet osmanthus) ѧ��(Prunus serrulata)
˫��Ҷֲ�Ǿޱ�ơ���Ҷ��ľ����10��25�ס���Ƥ��ɫ����Ƥ�ס�
Ҷ��Բ�Σ�ҶԵ�о�ݡ���3��5�仨���ɡ���������״���򣬻���
��ɫ��ۺ�ɫ��4��5�¿��š�7�¹��죬�˹����Σ���ɫ��
ԭ���й����ձ������ʡ�ϲ��ˮ���õķ���������ʪ�󻷾���������
�Ұ�������ɽ��Ϫ�ԣ��������С�һ���ü޽ӷ�ֳ������Ʒ����
�����֡�ӣ���Ǵ�����Ҫ�ۻ���ľ��԰���г���ֲ�ڵ�·���ԣ���ɽ
���ϡ�Ҷ�ͺ��ʿ���ҩ��ľ���ǵ�̹��յĺò��ϡ�
���⣬��԰���г���������ӣ���У��ձ�ӣ��(Prunus ye-doensis)��
�ֳƶ���ӣ�����ߴ�16�ף���Ƥ������ɫ����������Ͳ��ë�����ڽ�
�̣�������ïʢ���ձ���ӣ(Prunus lannesiana)�����ڽ�������
�ذ꣬�ۺ�ɫ����������\n"NOR);
	set("unit", "��");
	set("value", 1000000);
	set("no_break", 1); // ������
	set("deadfly", 1); // �����ɵ�
	set("no_get", 1);
	set("no_give", 1);
	set("no_putin", 1); // ���ܷű��տ�
	set("no_putto", 1); // ���ܾ���
	set("no_stock", 1); // ���ܷźڵ�
	set("armor_type", "others");
	set("material", "silk"); // ������
	set("Fmaterial", "gem"); // ������
	set("no_sell", "��ô����ӣ��������ҲҪ��Ǯ��\n");
	set("no_drop", "�Ե���ӣ�����䣬�����Ե���һ�����룬���Ǻú���ϧ���ɡ�\n");
	set("no_give", "ӣ��������Ҫ��ϧ�������������ˡ�\n");
	set("no_put", "ӣ��������Ҫչʾ����������˽�صġ�\n");
	set("armor_prop/armor", 2);
	set("armor_prop/personality", 1);
	set("unequip_msg","$N��Ư����"+query("name")+"�������������������\n");
	set("wear_msg", "$N��һ��Ư����"+query("name")+"С�ĵ����˳�������������ϡ�\n" );
	setup();
}

