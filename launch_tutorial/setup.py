from setuptools import setup

package_name = 'launch_tutorial'

setup(
    name=package_name,
    version='0.0.0',
    packages=[package_name],
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
        ('share/' + package_name + '/launch', [
            'launch/example_main.launch.py',
            'launch/example_substitutions.launch.py'
        ]),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='jasom',
    maintainer_email='jasom@example.com',
    description='Launch tutorial package',
    license='Apache-2.0',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [],
    },
)

